name: Build CryptoFloatMonitor - WS FIX 2026-11-05

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
    env:
      MSYS_NO_PATHCONV: '1'
      MSYS2_ARG_CONV_EXCL: '*'
    defaults:
      run:
        shell: bash
    steps:
      - name: Checkout source
        uses: actions/checkout@v4

      - name: Verify inputs and compiler
        run: |
          test -f binance.cpp || { echo 'Missing binance.cpp in repository root'; exit 1; }
          clang++ --version
          lld-link --version
          echo "WORKFLOW_MARKER=WS_FIXED_20261105"
          echo "Source: binance.cpp"

      - name: Generate import libraries (including WebSocket APIs)
        run: |
          mkdir -p build
          make_lib() {
            local dll="$1"; shift
            local lib="$1"; shift
            {
              echo "LIBRARY ${dll}"
              echo "EXPORTS"
              for s in "$@"; do echo "$s"; done
            } > "build/${lib%.lib}.def"
            lld-link -lib -machine:x64 "-def:build/${lib%.lib}.def" "-out:build/$lib"
          }
          make_lib kernel32.dll kernel32.lib GetModuleHandleW GetModuleFileNameW ExitProcess GetEnvironmentVariableW GetCommandLineW CreateDirectoryW CreateFileW ReadFile WriteFile CloseHandle CreateThread Sleep GetLastError lstrlenW lstrcpyW lstrcatW lstrcmpW WideCharToMultiByte MultiByteToWideChar
          make_lib user32.dll user32.lib RegisterClassW CreateWindowExW DestroyWindow ShowWindow UpdateWindow SetWindowPos MoveWindow GetWindowRect GetWindowLongW SetWindowLongW SetLayeredWindowAttributes SetWindowRgn LoadIconW LoadImageW LoadCursorW DefWindowProcW GetMessageW TranslateMessage DispatchMessageW PostQuitMessage PostMessageW InvalidateRect BeginPaint EndPaint GetClientRect SetCapture ReleaseCapture GetCursorPos ScreenToClient CreatePopupMenu AppendMenuW DestroyMenu TrackPopupMenu SetForegroundWindow SetFocus GetWindowTextW SetTimer KillTimer DrawTextA
          make_lib gdi32.dll gdi32.lib CreateSolidBrush SelectObject DeleteObject SetBkMode SetTextColor Rectangle RoundRect MoveToEx LineTo GetStockObject CreateFontA CreatePen GetTextExtentPoint32A CreateRoundRectRgn
          make_lib shell32.dll shell32.lib Shell_NotifyIconW
          make_lib advapi32.dll advapi32.lib RegCreateKeyExW RegSetValueExW RegDeleteValueW RegCloseKey
          make_lib winhttp.dll winhttp.lib WinHttpOpen WinHttpConnect WinHttpOpenRequest WinHttpSendRequest WinHttpReceiveResponse WinHttpQueryDataAvailable WinHttpReadData WinHttpCloseHandle WinHttpSetTimeouts WinHttpSetOption WinHttpWebSocketCompleteUpgrade WinHttpWebSocketSend WinHttpWebSocketReceive WinHttpWebSocketClose
          make_lib msvcrt.dll msvcrt.lib sprintf _snprintf strtod strstr strchr strcmp atoi strlen memcpy memset

      - name: Install ImageMagick if needed
        if: hashFiles('logo.png') != ''
        shell: pwsh
        run: |
          if (-not (Get-Command magick -ErrorAction SilentlyContinue)) {
            choco install imagemagick -y --no-progress
          }

      - name: Compile icon resource if logo.png exists
        if: hashFiles('logo.png') != ''
        run: |
          magick logo.png -define icon:auto-resize=256,128,64,48,32,16 build/appicon.ico
          printf '1 ICON "build/appicon.ico"\n' > build/app.rc
          llvm-rc build/app.rc

      - name: Build Windows x64 EXE
        run: |
          clang++ --target=x86_64-pc-windows-msvc -std=c++17 -O0 \
            -fno-exceptions -fno-rtti -fno-stack-protector -fno-builtin \
            -c binance.cpp -o build/binance.obj
          resources=()
          if [ -f build/app.res ]; then resources+=(build/app.res); fi
          lld-link -subsystem:windows -entry:WinMainCRTStartup -nodefaultlib \
            -out:CryptoFloatMonitor.exe \
            build/binance.obj "${resources[@]}" \
            build/kernel32.lib build/user32.lib build/gdi32.lib build/shell32.lib \
            build/advapi32.lib build/winhttp.lib build/msvcrt.lib
          test -s CryptoFloatMonitor.exe

      - name: Upload EXE
        uses: actions/upload-artifact@v4
        with:
          name: CryptoFloatMonitor-EXE
          path: CryptoFloatMonitor.exe
          if-no-files-found: error
