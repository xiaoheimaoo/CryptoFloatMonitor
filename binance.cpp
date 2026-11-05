name: Build CryptoFloatMonitor (Windows PowerShell)

on:
  workflow_dispatch:
  push:
    paths:
      - 'binance.cpp'
      - 'logo.png'
      - '.github/workflows/build.yml'

jobs:
  build:
    runs-on: windows-latest
    defaults:
      run:
        shell: pwsh

    steps:
      - name: Checkout
        uses: actions/checkout@v4

      - name: Generate Windows import libraries
        run: |
          $ErrorActionPreference = 'Stop'
          New-Item -ItemType Directory -Force build | Out-Null
          if (-not (Test-Path binance.cpp)) { throw 'Missing binance.cpp in repository root' }

          function Make-Lib([string]$dll, [string]$lib, [string]$symbols) {
            $defPath = Join-Path 'build' ($lib -replace '\.lib$', '.def')
            $libPath = Join-Path 'build' $lib
            $contents = @("LIBRARY $dll", 'EXPORTS') + ($symbols -split '\s+')
            [System.IO.File]::WriteAllLines((Join-Path (Get-Location).Path $defPath), [string[]]$contents)
            & lld-link /lib /machine:x64 "/def:$defPath" "/out:$libPath"
            if ($LASTEXITCODE -ne 0) { throw "Import library generation failed: $lib" }
          }

          Make-Lib 'kernel32.dll' 'kernel32.lib' 'GetModuleHandleW GetModuleFileNameW ExitProcess GetEnvironmentVariableW GetCommandLineW CreateDirectoryW CreateFileW ReadFile WriteFile CloseHandle CreateThread Sleep GetLastError lstrlenW lstrcpyW lstrcatW lstrcmpW WideCharToMultiByte MultiByteToWideChar'
          Make-Lib 'user32.dll' 'user32.lib' 'RegisterClassW CreateWindowExW DestroyWindow ShowWindow UpdateWindow SetWindowPos MoveWindow GetWindowRect GetWindowLongW SetWindowLongW SetLayeredWindowAttributes SetWindowRgn LoadIconW LoadImageW LoadCursorW DefWindowProcW GetMessageW TranslateMessage DispatchMessageW PostQuitMessage PostMessageW InvalidateRect BeginPaint EndPaint GetClientRect SetCapture ReleaseCapture GetCursorPos ScreenToClient CreatePopupMenu AppendMenuW DestroyMenu TrackPopupMenu SetForegroundWindow SetFocus GetWindowTextW SetTimer KillTimer DrawTextA'
          Make-Lib 'gdi32.dll' 'gdi32.lib' 'CreateSolidBrush SelectObject DeleteObject SetBkMode SetTextColor Rectangle RoundRect MoveToEx LineTo GetStockObject CreateFontA CreatePen GetTextExtentPoint32A CreateRoundRectRgn'
          Make-Lib 'shell32.dll' 'shell32.lib' 'Shell_NotifyIconW'
          Make-Lib 'advapi32.dll' 'advapi32.lib' 'RegCreateKeyExW RegSetValueExW RegDeleteValueW RegCloseKey'
          Make-Lib 'winhttp.dll' 'winhttp.lib' 'WinHttpOpen WinHttpConnect WinHttpOpenRequest WinHttpSendRequest WinHttpReceiveResponse WinHttpQueryDataAvailable WinHttpReadData WinHttpCloseHandle WinHttpSetTimeouts WinHttpSetOption WinHttpWebSocketCompleteUpgrade WinHttpWebSocketSend WinHttpWebSocketReceive WinHttpWebSocketClose'
          Make-Lib 'msvcrt.dll' 'msvcrt.lib' 'sprintf _snprintf strtod strstr strchr strcmp atoi strlen memcpy memset'

      - name: Install ImageMagick when logo exists
        if: hashFiles('logo.png') != ''
        run: |
          if (-not (Get-Command magick -ErrorAction SilentlyContinue)) {
            choco install imagemagick -y --no-progress
            if ($LASTEXITCODE -ne 0) { throw 'ImageMagick installation failed' }
            $magickExe = Get-ChildItem 'C:\Program Files' -Filter magick.exe -Recurse -ErrorAction SilentlyContinue | Select-Object -First 1 -ExpandProperty FullName
            if (-not $magickExe) { throw 'ImageMagick installed but magick.exe not found' }
            $env:PATH = (Split-Path $magickExe -Parent) + ';' + $env:PATH
          }

      - name: Compile EXE (with optional icon)
        run: |
          $ErrorActionPreference = 'Stop'
          $resourceFiles = @()
          if (Test-Path 'logo.png') {
            & magick 'logo.png' '-define' 'icon:auto-resize=256,128,64,48,32,16' 'build/appicon.ico'
            if ($LASTEXITCODE -ne 0) { throw 'Icon conversion failed' }
            [System.IO.File]::WriteAllText((Join-Path (Get-Location).Path 'build/app.rc'), '1 ICON "build/appicon.ico"' + [Environment]::NewLine)
            & llvm-rc '/fo' 'build/app.res' 'build/app.rc'
            if ($LASTEXITCODE -ne 0) { throw 'Resource compilation failed' }
            $resourceFiles += 'build/app.res'
          }

          & clang++ '--target=x86_64-pc-windows-msvc' '-std=c++17' '-O0' '-fno-exceptions' '-fno-rtti' '-fno-stack-protector' '-fno-builtin' '-c' 'binance.cpp' '-o' 'build/binance.obj'
          if ($LASTEXITCODE -ne 0) { throw 'C++ compilation failed' }

          $linkArgs = @('/subsystem:windows', '/entry:WinMainCRTStartup', '/nodefaultlib', '/out:CryptoFloatMonitor.exe', 'build/binance.obj') + $resourceFiles + @(
            'build/kernel32.lib', 'build/user32.lib', 'build/gdi32.lib', 'build/shell32.lib',
            'build/advapi32.lib', 'build/winhttp.lib', 'build/msvcrt.lib'
          )
          & lld-link @linkArgs
          if ($LASTEXITCODE -ne 0) { throw 'EXE link failed' }
          if (-not (Test-Path 'CryptoFloatMonitor.exe')) { throw 'EXE not created' }

      - name: Upload EXE
        uses: actions/upload-artifact@v4
        with:
          name: CryptoFloatMonitor-EXE
          path: CryptoFloatMonitor.exe
          if-no-files-found: error
