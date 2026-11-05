    case WM_CLOSE:
        DestroyWindow(hwnd); return 0;
    case WM_DESTROY:
        if (g.inputHwnd == hwnd) { g.inputHwnd = NULL; g.inputEdit = NULL; }
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

static void ShowInputWindow(HWND owner) {
    if (g.inputHwnd) { SetForegroundWindow(g.inputHwnd); if (g.inputEdit) SetFocus(g.inputEdit); return; }
    RECT r; GetWindowRect(owner, &r);
    int ww = 292, hh = 152;
    int x = r.left + ((r.right - r.left) - ww) / 2;
    int y = r.top + ((r.bottom - r.top) - hh) / 2;
    if (x < 20) x = 20; if (y < 20) y = 20;
    g.inputHwnd = CreateWindowExW(WS_EX_TOOLWINDOW | WS_EX_TOPMOST, kInputClassName, L"手动输入币种",
                                  WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU,
                                  x, y, ww, hh, owner, NULL, g.inst, NULL);
}

static void HandleCommand(UINT id) {
    if(id >= ID_SYMBOL_BTC && id <= ID_SYMBOL_XAU) { g.symbol = (int)(id - ID_SYMBOL_BTC); AtomicExchange(&g.wsGeneration,g.wsGeneration+1); g.histCount=0; g.historyStatus=0; g.lastPrice=0; g.prevPrice=0; g.percent=0; SaveState(); RefreshData(1); }
    else if(id == ID_SYMBOL_CUSTOM) { g.symbol = kCustomSymbolIndex; AtomicExchange(&g.wsGeneration,g.wsGeneration+1); g.histCount=0; g.historyStatus=0; g.lastPrice=0; g.prevPrice=0; g.percent=0; SaveState(); RefreshData(1); }
    else if(id == ID_CUSTOM_INPUT) { ShowInputWindow(g.hwnd); }
    else if(id == ID_TOGGLE_MODE) { g.mode = (g.mode == MODE_PRICE) ? MODE_CHART : MODE_PRICE; SaveState(); if(g.mode==MODE_CHART && g.histCount<2) RefreshData(1); InvalidateRect(g.hwnd, NULL, false); }
    else if(id == ID_LOCK) { g.locked = !g.locked; ApplyLockedStyle(); SaveState(); InvalidateRect(g.hwnd, NULL, false); }
    else if(id == ID_AUTOSTART) { SetAutoStart(!g.autostart); }
    else if(id == ID_OPA_30 || id == ID_OPA_50 || id == ID_OPA_70 || id == ID_OPA_90 || id == ID_OPA_100) {
        int vals[] = {30,50,70,90,100}; g.opacity = vals[id - ID_OPA_30]; ApplyOpacity(); SaveState();
    }
    else if(id == ID_REFRESH) { AtomicExchange(&g.wsGeneration,g.wsGeneration+1); RefreshData(1); }
    else if(id == ID_EXIT) { DestroyWindow(g.hwnd); }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch(msg) {
    case WM_CREATE:
        g.hwnd = hwnd; ApplyLockedStyle(); ApplyRoundRegion(hwnd); AddTrayIcon(1); SetTimer(hwnd, TIMER_REFRESH, 5000, NULL); RefreshData(1); return 0;
    case WM_DATA_READY:
        InvalidateRect(hwnd, NULL, false); return 0;
    case WM_TIMER:
        if(wp == TIMER_REFRESH) {
            if(g.historyStatus==0 && g.historyLoading==0) FetchHistoryAsync();
            RefreshData(0);InvalidateRect(hwnd,NULL,false);
        } return 0;
    case WM_SIZE:
        ApplyRoundRegion(hwnd); SaveState(); return 0;
    case WM_ERASEBKGND: return 1;
    case WM_NCHITTEST:
        if (g.locked) return HTTRANSPARENT;
        break;
    case WM_PAINT: OnPaint(hwnd); return 0;
    case WM_RBUTTONUP:
        if(!g.locked) ShowContextMenu(hwnd);
        return 0;
    case WM_TRAYICON:
        if(lp == WM_RBUTTONUP) ShowContextMenu(hwnd);
        if(lp == WM_LBUTTONDBLCLK) { ShowWindow(hwnd, SW_RESTORE); SetForegroundWindow(hwnd); }
        return 0;
    case WM_COMMAND: HandleCommand((UINT)LOWORD_(wp)); return 0;
    case WM_LBUTTONDOWN:
        if(!g.locked) {
            RECT cr; GetClientRect(hwnd, &cr);
            int mx=GET_X_LPARAM_(lp), my=GET_Y_LPARAM_(lp);
            GetCursorPos(&g.dragStart); GetWindowRect(hwnd, &g.winStart);
            if(mx > cr.right-28 && my > cr.bottom-28) g.resizing=1; else g.dragging=1;
            SetCapture(hwnd);
        }
        return 0;
    case WM_MOUSEMOVE:
        if(!g.locked && ((wp & MK_LBUTTON) != 0) && (g.dragging || g.resizing)) {
            POINT p; GetCursorPos(&p);
            int dx = p.x - g.dragStart.x; int dy = p.y - g.dragStart.y;
            if(g.dragging) MoveWindow(hwnd, g.winStart.left+dx, g.winStart.top+dy, g.winStart.right-g.winStart.left, g.winStart.bottom-g.winStart.top, true);
            if(g.resizing) {
                int nw = MaxI(1, (g.winStart.right-g.winStart.left)+dx);
                int nh = MaxI(1, (g.winStart.bottom-g.winStart.top)+dy);
                MoveWindow(hwnd, g.winStart.left, g.winStart.top, nw, nh, true);
            }
        }
        return 0;
    case WM_LBUTTONUP:
        if(g.dragging || g.resizing) { g.dragging=0; g.resizing=0; ReleaseCapture(); SaveState(); }
        return 0;
    case WM_CLOSE: DestroyWindow(hwnd); return 0;
    case WM_DESTROY:
        SaveState(); KillTimer(hwnd, TIMER_REFRESH); AddTrayIcon(0); PostQuitMessage(0); ExitProcess(0); return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

static void ParseCommandLine() {
    // Proxy now follows Windows system proxy automatically; --proxy is ignored.
}
static int AppMain(HINSTANCE inst) {
    ZeroMem(&g, sizeof(g)); g.inst = inst; LoadState(); ParseCommandLine(); g.appIcon = LoadAppIcon(inst);
    WNDCLASSW wc; ZeroMem(&wc, sizeof(wc));
    wc.style = CS_HREDRAW | CS_VREDRAW; wc.lpfnWndProc = WndProc; wc.hInstance = inst;
    wc.hIcon = g.appIcon ? g.appIcon : LoadIconW(NULL, IDI_APPLICATION); wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wc.lpszClassName = kClassName;
    RegisterClassW(&wc);
    WNDCLASSW iwc; ZeroMem(&iwc, sizeof(iwc));
    iwc.style = CS_HREDRAW | CS_VREDRAW; iwc.lpfnWndProc = InputWndProc; iwc.hInstance = inst;
    iwc.hIcon = g.appIcon ? g.appIcon : LoadIconW(NULL, IDI_APPLICATION); iwc.hCursor = LoadCursorW(NULL, IDC_ARROW);
    iwc.lpszClassName = kInputClassName;
    RegisterClassW(&iwc);
    DWORD exStyle = WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_LAYERED | (g.locked ? WS_EX_TRANSPARENT : 0);
    HWND hwnd = CreateWindowExW(exStyle, kClassName, kAppName, WS_POPUP|WS_VISIBLE,
                                g.x, g.y, g.w, g.h, NULL, NULL, inst, NULL);
    if(!hwnd) return 1;
    g.hwnd = hwnd; ShowWindow(hwnd, SW_SHOW); UpdateWindow(hwnd);
    MSG msg;
    while(GetMessageW(&msg, NULL, 0, 0)) { TranslateMessage(&msg); DispatchMessageW(&msg); }
    return 0;
}

extern "C" int WINAPI WinMainCRTStartup() {
    HINSTANCE inst = GetModuleHandleW(NULL);
    return AppMain(inst);
}
