// CryptoFloatMonitor.cpp
// A tiny native Win32 floating crypto monitor. No MFC/Qt/.NET, no Windows SDK headers required.
// Build in this environment with clang + lld-link using generated import libraries.

#define NULL 0
#define true 1
#define false 0

typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned int        UINT;
typedef unsigned long       DWORD;
typedef long                LONG;
typedef long long           LONGLONG;
typedef unsigned long long  ULONGLONG;
typedef unsigned long long  size_t;
typedef int                 BOOL;
typedef long long           LPARAM;
typedef unsigned long long  WPARAM;
typedef long long           LRESULT;
typedef void*               HANDLE;
typedef void*               HWND;
typedef void*               HINSTANCE;
typedef void*               HICON;
typedef void*               HCURSOR;
typedef void*               HBRUSH;
typedef void*               HFONT;
typedef void*               HGDIOBJ;
typedef void*               HMENU;
typedef void*               HDC;
typedef void*               HRGN;
typedef void*               HKEY;
typedef void*               HINTERNET;
typedef const wchar_t*      LPCWSTR;
typedef wchar_t*            LPWSTR;
typedef const char*         LPCSTR;
typedef char*               LPSTR;
typedef void*               LPVOID;
typedef DWORD*              LPDWORD;
typedef unsigned int        COLORREF;
typedef LRESULT (__stdcall *WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef DWORD (__stdcall *LPTHREAD_START_ROUTINE)(void*);
typedef LONG LSTATUS;

struct POINT { LONG x; LONG y; };
struct RECT { LONG left; LONG top; LONG right; LONG bottom; };
struct SIZE_ { LONG cx; LONG cy; };
struct MSG { HWND hwnd; UINT message; WPARAM wParam; LPARAM lParam; DWORD time; POINT pt; DWORD lPrivate; };
struct WNDCLASSW {
    UINT style; WNDPROC lpfnWndProc; int cbClsExtra; int cbWndExtra; HINSTANCE hInstance;
    HICON hIcon; HCURSOR hCursor; HBRUSH hbrBackground; LPCWSTR lpszMenuName; LPCWSTR lpszClassName;
};
struct PAINTSTRUCT { HDC hdc; BOOL fErase; RECT rcPaint; BOOL fRestore; BOOL fIncUpdate; BYTE rgbReserved[32]; };
struct GUID { DWORD Data1; WORD Data2; WORD Data3; BYTE Data4[8]; };
struct NOTIFYICONDATAW {
    DWORD cbSize; HWND hWnd; UINT uID; UINT uFlags; UINT uCallbackMessage; HICON hIcon; wchar_t szTip[128];
    DWORD dwState; DWORD dwStateMask; wchar_t szInfo[256]; union { UINT uTimeout; UINT uVersion; } DUMMYUNIONNAME;
    wchar_t szInfoTitle[64]; DWORD dwInfoFlags; GUID guidItem; HICON hBalloonIcon;
};
struct WINHTTP_PROXY_INFO { DWORD dwAccessType; LPWSTR lpszProxy; LPWSTR lpszProxyBypass; };

#define WINAPI __stdcall
#define CALLBACK __stdcall
#define CDECL __cdecl

#define WS_POPUP            0x80000000UL
#define WS_VISIBLE          0x10000000UL
#define WS_CHILD            0x40000000UL
#define WS_BORDER           0x00800000UL
#define WS_CAPTION          0x00C00000UL
#define WS_SYSMENU          0x00080000UL
#define ES_AUTOHSCROLL      0x0080UL
#define BS_DEFPUSHBUTTON    0x00000001UL
#define WS_EX_TOPMOST       0x00000008UL
#define WS_EX_TOOLWINDOW    0x00000080UL
#define WS_EX_LAYERED       0x00080000UL
#define WS_EX_TRANSPARENT  0x00000020UL
#define CS_HREDRAW          0x0002
#define CS_VREDRAW          0x0001
#define CW_USEDEFAULT       0x80000000U
#define SW_SHOW             5
#define SW_HIDE             0
#define SW_RESTORE          9
#define LWA_ALPHA           0x00000002
#define IMAGE_ICON          1
#define LR_LOADFROMFILE     0x00000010
#define LR_DEFAULTSIZE      0x00000040
#define GWL_EXSTYLE         (-20)
#define WM_CREATE           0x0001
#define WM_DESTROY          0x0002
#define WM_PAINT            0x000F
#define WM_TIMER            0x0113
#define WM_LBUTTONDOWN      0x0201
#define WM_LBUTTONUP        0x0202
#define WM_MOUSEMOVE        0x0200
#define WM_RBUTTONUP        0x0205
#define WM_COMMAND          0x0111
#define WM_APP              0x8000
#define WM_CLOSE            0x0010
#define WM_SIZE             0x0005
#define WM_ERASEBKGND       0x0014
#define WM_NCHITTEST        0x0084
#define HTTRANSPARENT       (-1)
#define WM_LBUTTONDBLCLK    0x0203
#define WM_DATA_READY        (WM_APP + 8)
#define MK_LBUTTON          0x0001
#define DT_CENTER           0x00000001
#define DT_VCENTER          0x00000004
#define DT_SINGLELINE       0x00000020
#define DT_LEFT             0x00000000
#define DT_RIGHT            0x00000002
#define TRANSPARENT         1
#define PS_SOLID            0
#define PS_DASH             1
#define DEFAULT_CHARSET     1
#define OUT_DEFAULT_PRECIS  0
#define CLIP_DEFAULT_PRECIS 0
#define DEFAULT_QUALITY     0
#define DEFAULT_PITCH       0
#define FW_NORMAL           400
#define FW_BOLD             700
#define FW_BLACK            900
#define MF_STRING           0x00000000UL
#define MF_SEPARATOR        0x00000800UL
#define MF_POPUP            0x00000010UL
#define MF_CHECKED          0x00000008UL
#define MF_UNCHECKED        0x00000000UL
#define TPM_RIGHTBUTTON     0x0002UL
#define TPM_RETURNCMD       0x0100UL
#define NIM_ADD             0x00000000
#define NIM_MODIFY          0x00000001
#define NIM_DELETE          0x00000002
#define NIF_MESSAGE         0x00000001
#define NIF_ICON            0x00000002
#define NIF_TIP             0x00000004
#define IDI_APPLICATION     ((LPCWSTR)32512)
#define IDI_APPICON         ((LPCWSTR)1)
#define IDC_ARROW           ((LPCWSTR)32512)
#define HKEY_CURRENT_USER   ((HKEY)(ULONGLONG)0x80000001)
#define KEY_SET_VALUE       0x0002
#define KEY_QUERY_VALUE     0x0001
#define REG_SZ              1
#define ERROR_SUCCESS       0
#define INVALID_HANDLE_VALUE ((HANDLE)(LONGLONG)-1)
#define GENERIC_READ        0x80000000UL
#define GENERIC_WRITE       0x40000000UL
#define FILE_SHARE_READ     0x00000001UL
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define FILE_ATTRIBUTE_NORMAL 0x00000080UL
#define INTERNET_DEFAULT_HTTPS_PORT 443
#define WINHTTP_ACCESS_TYPE_DEFAULT_PROXY 0
#define WINHTTP_ACCESS_TYPE_NAMED_PROXY 3
#define WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY 4
#define WINHTTP_NO_PROXY_NAME NULL
#define WINHTTP_NO_PROXY_BYPASS NULL
#define WINHTTP_NO_REFERER NULL
#define WINHTTP_DEFAULT_ACCEPT_TYPES NULL
#define WINHTTP_FLAG_SECURE 0x00800000

extern "C" {
__declspec(dllimport) HINSTANCE WINAPI GetModuleHandleW(LPCWSTR);
__declspec(dllimport) DWORD WINAPI GetModuleFileNameW(HINSTANCE, LPWSTR, DWORD);
__declspec(dllimport) DWORD WINAPI GetEnvironmentVariableW(LPCWSTR, LPWSTR, DWORD);
__declspec(dllimport) BOOL WINAPI CreateDirectoryW(LPCWSTR, void*);
__declspec(dllimport) HANDLE WINAPI CreateFileW(LPCWSTR, DWORD, DWORD, void*, DWORD, DWORD, HANDLE);
__declspec(dllimport) BOOL WINAPI ReadFile(HANDLE, LPVOID, DWORD, LPDWORD, void*);
__declspec(dllimport) BOOL WINAPI WriteFile(HANDLE, const void*, DWORD, LPDWORD, void*);
__declspec(dllimport) BOOL WINAPI CloseHandle(HANDLE);
__declspec(dllimport) void WINAPI ExitProcess(UINT);
__declspec(dllimport) HANDLE WINAPI CreateThread(void*, size_t, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD);
__declspec(dllimport) BOOL WINAPI SetTimer(HWND, unsigned long long, UINT, void*);
__declspec(dllimport) BOOL WINAPI KillTimer(HWND, unsigned long long);
__declspec(dllimport) void WINAPI Sleep(DWORD);
__declspec(dllimport) DWORD WINAPI GetLastError();
__declspec(dllimport) LPWSTR WINAPI GetCommandLineW();
__declspec(dllimport) int WINAPI lstrlenW(LPCWSTR);
__declspec(dllimport) LPWSTR WINAPI lstrcpyW(LPWSTR, LPCWSTR);
__declspec(dllimport) LPWSTR WINAPI lstrcatW(LPWSTR, LPCWSTR);
__declspec(dllimport) int WINAPI lstrcmpW(LPCWSTR, LPCWSTR);
__declspec(dllimport) int WINAPI WideCharToMultiByte(UINT, DWORD, LPCWSTR, int, LPSTR, int, LPCSTR, BOOL*);
__declspec(dllimport) int WINAPI MultiByteToWideChar(UINT, DWORD, LPCSTR, int, LPWSTR, int);

__declspec(dllimport) unsigned short WINAPI RegisterClassW(const WNDCLASSW*);
__declspec(dllimport) HWND WINAPI CreateWindowExW(DWORD, LPCWSTR, LPCWSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID);
__declspec(dllimport) BOOL WINAPI DestroyWindow(HWND);
__declspec(dllimport) BOOL WINAPI ShowWindow(HWND, int);
__declspec(dllimport) BOOL WINAPI UpdateWindow(HWND);
__declspec(dllimport) BOOL WINAPI SetWindowPos(HWND, HWND, int, int, int, int, UINT);
__declspec(dllimport) BOOL WINAPI MoveWindow(HWND, int, int, int, int, BOOL);
__declspec(dllimport) BOOL WINAPI GetWindowRect(HWND, RECT*);
__declspec(dllimport) LONG WINAPI GetWindowLongW(HWND, int);
__declspec(dllimport) LONG WINAPI SetWindowLongW(HWND, int, LONG);
__declspec(dllimport) BOOL WINAPI SetLayeredWindowAttributes(HWND, COLORREF, BYTE, DWORD);
__declspec(dllimport) int WINAPI SetWindowRgn(HWND, HRGN, BOOL);
__declspec(dllimport) HICON WINAPI LoadIconW(HINSTANCE, LPCWSTR);
__declspec(dllimport) HANDLE WINAPI LoadImageW(HINSTANCE, LPCWSTR, UINT, int, int, UINT);
__declspec(dllimport) HCURSOR WINAPI LoadCursorW(HINSTANCE, LPCWSTR);
__declspec(dllimport) LRESULT WINAPI DefWindowProcW(HWND, UINT, WPARAM, LPARAM);
__declspec(dllimport) BOOL WINAPI GetMessageW(MSG*, HWND, UINT, UINT);
__declspec(dllimport) BOOL WINAPI TranslateMessage(const MSG*);
__declspec(dllimport) LRESULT WINAPI DispatchMessageW(const MSG*);
__declspec(dllimport) void WINAPI PostQuitMessage(int);
__declspec(dllimport) BOOL WINAPI PostMessageW(HWND, UINT, WPARAM, LPARAM);
__declspec(dllimport) void WINAPI InvalidateRect(HWND, const RECT*, BOOL);
__declspec(dllimport) HDC WINAPI BeginPaint(HWND, PAINTSTRUCT*);
__declspec(dllimport) BOOL WINAPI EndPaint(HWND, const PAINTSTRUCT*);
__declspec(dllimport) BOOL WINAPI GetClientRect(HWND, RECT*);
__declspec(dllimport) BOOL WINAPI SetCapture(HWND);
__declspec(dllimport) BOOL WINAPI ReleaseCapture();
__declspec(dllimport) BOOL WINAPI GetCursorPos(POINT*);
__declspec(dllimport) BOOL WINAPI ScreenToClient(HWND, POINT*);
__declspec(dllimport) HMENU WINAPI CreatePopupMenu();
__declspec(dllimport) BOOL WINAPI AppendMenuW(HMENU, UINT, unsigned long long, LPCWSTR);
__declspec(dllimport) BOOL WINAPI DestroyMenu(HMENU);
__declspec(dllimport) UINT WINAPI TrackPopupMenu(HMENU, UINT, int, int, int, HWND, const RECT*);
__declspec(dllimport) BOOL WINAPI SetForegroundWindow(HWND);
__declspec(dllimport) int WINAPI GetWindowTextW(HWND, LPWSTR, int);
__declspec(dllimport) HWND WINAPI SetFocus(HWND);

__declspec(dllimport) HBRUSH WINAPI CreateSolidBrush(COLORREF);
__declspec(dllimport) HGDIOBJ WINAPI SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) BOOL WINAPI DeleteObject(HGDIOBJ);
__declspec(dllimport) int WINAPI SetBkMode(HDC, int);
__declspec(dllimport) COLORREF WINAPI SetTextColor(HDC, COLORREF);
__declspec(dllimport) BOOL WINAPI Rectangle(HDC, int, int, int, int);
__declspec(dllimport) BOOL WINAPI RoundRect(HDC, int, int, int, int, int, int);
__declspec(dllimport) int WINAPI DrawTextA(HDC, LPCSTR, int, RECT*, UINT);
__declspec(dllimport) BOOL WINAPI MoveToEx(HDC, int, int, POINT*);
__declspec(dllimport) BOOL WINAPI LineTo(HDC, int, int);
__declspec(dllimport) HGDIOBJ WINAPI GetStockObject(int);
__declspec(dllimport) HFONT WINAPI CreateFontA(int, int, int, int, int, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, LPCSTR);
__declspec(dllimport) HGDIOBJ WINAPI CreatePen(int, int, COLORREF);
__declspec(dllimport) BOOL WINAPI GetTextExtentPoint32A(HDC, LPCSTR, int, SIZE_*);
__declspec(dllimport) HRGN WINAPI CreateRoundRectRgn(int, int, int, int, int, int);

__declspec(dllimport) BOOL WINAPI Shell_NotifyIconW(DWORD, NOTIFYICONDATAW*);

__declspec(dllimport) LSTATUS WINAPI RegCreateKeyExW(HKEY, LPCWSTR, DWORD, LPWSTR, DWORD, DWORD, void*, HKEY*, DWORD*);
__declspec(dllimport) LSTATUS WINAPI RegSetValueExW(HKEY, LPCWSTR, DWORD, DWORD, const BYTE*, DWORD);
__declspec(dllimport) LSTATUS WINAPI RegDeleteValueW(HKEY, LPCWSTR);
__declspec(dllimport) LSTATUS WINAPI RegCloseKey(HKEY);

__declspec(dllimport) HINTERNET WINAPI WinHttpOpen(LPCWSTR, DWORD, LPCWSTR, LPCWSTR, DWORD);
__declspec(dllimport) HINTERNET WINAPI WinHttpConnect(HINTERNET, LPCWSTR, unsigned short, DWORD);
__declspec(dllimport) HINTERNET WINAPI WinHttpOpenRequest(HINTERNET, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR*, DWORD);
__declspec(dllimport) BOOL WINAPI WinHttpSendRequest(HINTERNET, LPCWSTR, DWORD, LPVOID, DWORD, DWORD, DWORD);
__declspec(dllimport) BOOL WINAPI WinHttpReceiveResponse(HINTERNET, LPVOID);
__declspec(dllimport) BOOL WINAPI WinHttpQueryDataAvailable(HINTERNET, LPDWORD);
__declspec(dllimport) BOOL WINAPI WinHttpReadData(HINTERNET, LPVOID, DWORD, LPDWORD);
__declspec(dllimport) BOOL WINAPI WinHttpCloseHandle(HINTERNET);
__declspec(dllimport) BOOL WINAPI WinHttpSetTimeouts(HINTERNET, int, int, int, int);

__declspec(dllimport) int CDECL sprintf(char*, const char*, ...);
__declspec(dllimport) int CDECL _snprintf(char*, size_t, const char*, ...);
__declspec(dllimport) double CDECL strtod(const char*, char**);
__declspec(dllimport) char* CDECL strstr(const char*, const char*);
__declspec(dllimport) char* CDECL strchr(const char*, int);
__declspec(dllimport) int CDECL strcmp(const char*, const char*);
__declspec(dllimport) int CDECL atoi(const char*);
__declspec(dllimport) size_t CDECL strlen(const char*);
__declspec(dllimport) void* CDECL memcpy(void*, const void*, size_t);
__declspec(dllimport) void* CDECL memset(void*, int, size_t);
}

#define RGB_(r,g,b) ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define LOWORD_(x) ((WORD)((ULONGLONG)(x) & 0xffff))
#define HIWORD_(x) ((WORD)((((ULONGLONG)(x)) >> 16) & 0xffff))
#define GET_X_LPARAM_(lp) ((int)(short)LOWORD_(lp))
#define GET_Y_LPARAM_(lp) ((int)(short)HIWORD_(lp))

extern "C" int _fltused = 0;

static const wchar_t* kClassName = L"VirtualCoinMonitorClass";
static const wchar_t* kInputClassName = L"VirtualCoinMonitorInputClass";
static const wchar_t* kAppName   = L"虚拟币监控";
static const wchar_t* kRunKey    = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
static const wchar_t* kRunValue  = L"虚拟币监控";
static const wchar_t* kFuturesHost = L"fapi.binance.com";
static const wchar_t* kSpotHost    = L"api.binance.com";
static const int kFixedSymbolCount = 6;
static const int kCustomSymbolIndex = 6;
// Display names do not include the USDT suffix. API symbols stay hidden.
static const char* kDisplayA[] = {"BTC", "ETH", "BNB", "SOL", "LTC", "XAU"};
static const wchar_t* kDisplayW[] = {L"BTC", L"ETH", L"BNB", L"SOL", L"LTC", L"XAU"};
// XAU is fetched through a Binance spot gold-backed pair and displayed as XAU.
static const wchar_t* kApiSymbolsW[] = {L"BTCUSDT", L"ETHUSDT", L"BNBUSDT", L"SOLUSDT", L"LTCUSDT", L"PAXGUSDT"};

enum { MODE_PRICE = 0, MODE_CHART = 1 };
enum {
    ID_SYMBOL_BTC = 1001, ID_SYMBOL_ETH, ID_SYMBOL_BNB, ID_SYMBOL_SOL, ID_SYMBOL_LTC, ID_SYMBOL_XAU,
    ID_SYMBOL_CUSTOM = 1070,
    ID_CUSTOM_INPUT = 1071,
    ID_TOGGLE_MODE = 1101,
    ID_LOCK = 1201,
    ID_OPA_30 = 1301, ID_OPA_50, ID_OPA_70, ID_OPA_90, ID_OPA_100,
    ID_AUTOSTART = 1401,
    ID_REFRESH = 1501,
    ID_EXIT = 1601,
    ID_INPUT_OK = 2001,
    ID_INPUT_CANCEL = 2002
};
#define TIMER_REFRESH 1
#define WM_TRAYICON (WM_APP + 7)
#define SWP_NOZORDER 0x0004
#define SWP_NOMOVE 0x0002
#define SWP_NOSIZE 0x0001
#define HWND_TOPMOST ((HWND)(LONGLONG)-1)
#define BLACK_BRUSH 4

struct AppState {
    HWND hwnd;
    HINSTANCE inst;
    int x, y, w, h;
    int symbol;
    int mode;
    int locked;
    int opacity;
    int autostart;
    int dragging;
    int resizing;
    POINT dragStart;
    RECT winStart;
    char status[128];
    char lastUpdate[64];
    double lastPrice;
    double prevPrice;
    double percent;
    double high24;
    double low24;
    double volume24;
    double history[180];
    double histOpen[180];
    double histHigh[180];
    double histLow[180];
    double histClose[180];
    int histCount;
    wchar_t configPath[512];
    wchar_t proxy[256];
    HICON appIcon;
    wchar_t customApiSymbol[64];
    wchar_t customDisplay[64];
    int customUseSpot;
    HWND inputHwnd;
    HWND inputEdit;
    volatile LONG fetching;
    volatile LONG pendingChart;
};
static AppState g;

static void ZeroMem(void* p, size_t n) { memset(p, 0, n); }
static double AbsD(double v) { return v < 0 ? -v : v; }
static int MinI(int a, int b) { return a < b ? a : b; }
static int MaxI(int a, int b) { return a > b ? a : b; }

static void CopyA(char* dst, const char* src, int cap) {
    if (!dst || cap <= 0) return;
    int i = 0;
    if (src) { for (; i < cap - 1 && src[i]; ++i) dst[i] = src[i]; }
    dst[i] = 0;
}
static void CopyW(wchar_t* dst, const wchar_t* src, int cap) {
    if (!dst || cap <= 0) return;
    int i = 0;
    if (src) { for (; i < cap - 1 && src[i]; ++i) dst[i] = src[i]; }
    dst[i] = 0;
}
static void AppendW(wchar_t* dst, const wchar_t* src, int cap) {
    int n = lstrlenW(dst);
    int i = 0;
    while (n + i < cap - 1 && src && src[i]) { dst[n+i] = src[i]; ++i; }
    dst[n+i] = 0;
}
static void CharToWide(const char* src, wchar_t* dst, int cap) {
    if (!dst || cap <= 0) return;
    int i=0; for (; i<cap-1 && src && src[i]; ++i) dst[i] = (wchar_t)(unsigned char)src[i];
    dst[i]=0;
}
static void WideToChar(const wchar_t* src, char* dst, int cap) {
    if (!dst || cap <= 0) return;
    int i=0; for (; i<cap-1 && src && src[i]; ++i) dst[i] = (src[i] < 128) ? (char)src[i] : '?';
    dst[i]=0;
}
static int StartsWithW(const wchar_t* s, const wchar_t* prefix) {
    int i=0; while(prefix[i]) { if(s[i] != prefix[i]) return 0; ++i; } return 1;
}
static int EndsWithW(const wchar_t* s, const wchar_t* suffix) {
    int ns = lstrlenW(s), nf = lstrlenW(suffix);
    if (nf > ns) return 0;
    for (int i = 0; i < nf; ++i) if (s[ns - nf + i] != suffix[i]) return 0;
    return 1;
}
static void StripQuoteSuffixW(const wchar_t* api, wchar_t* out, int cap) {
    CopyW(out, api, cap);
    const wchar_t* suffixes[] = {L"USDT", L"USDC", L"BUSD", L"FDUSD", L"BTC", L"ETH"};
    for (int k = 0; k < 6; ++k) {
        int ns = lstrlenW(out), nf = lstrlenW(suffixes[k]);
        if (nf < ns && EndsWithW(out, suffixes[k])) { out[ns - nf] = 0; return; }
    }
}
static void NormalizeManualSymbol(const wchar_t* input, wchar_t* apiOut, int apiCap, wchar_t* displayOut, int dispCap, int* useSpotOut) {
    wchar_t cleaned[64]; int n = 0;
    for (int i = 0; input && input[i] && n < 63; ++i) {
        wchar_t ch = input[i];
        if (ch == L' ' || ch == L'\t' || ch == L'\r' || ch == L'\n' || ch == L'/' || ch == L'-' || ch == L'_') continue;
        if (ch >= L'a' && ch <= L'z') ch = (wchar_t)(ch - 32);
        if ((ch >= L'A' && ch <= L'Z') || (ch >= L'0' && ch <= L'9')) cleaned[n++] = ch;
    }
    cleaned[n] = 0;
    if (n == 0) { CopyW(apiOut, L"BTCUSDT", apiCap); CopyW(displayOut, L"BTC", dispCap); *useSpotOut = 0; return; }
    if (lstrcmpW(cleaned, L"XAU") == 0) {
        CopyW(apiOut, L"PAXGUSDT", apiCap); CopyW(displayOut, L"XAU", dispCap); *useSpotOut = 1; return;
    }
    CopyW(apiOut, cleaned, apiCap);
    if (!EndsWithW(apiOut, L"USDT") && !EndsWithW(apiOut, L"USDC") && !EndsWithW(apiOut, L"BUSD") && !EndsWithW(apiOut, L"FDUSD")) {
        AppendW(apiOut, L"USDT", apiCap);
    }
    StripQuoteSuffixW(apiOut, displayOut, dispCap);
    *useSpotOut = (StartsWithW(apiOut, L"PAXG") ? 1 : 0);
}

static void BuildConfigPath() {
    wchar_t base[384]; ZeroMem(base, sizeof(base));
    DWORD n = GetEnvironmentVariableW(L"APPDATA", base, 360);
    if (n == 0 || n >= 360) {
        GetModuleFileNameW(NULL, base, 360);
        int len = lstrlenW(base);
        while (len > 0 && base[len-1] != L'\\' && base[len-1] != L'/') { base[len-1] = 0; --len; }
    }
    CopyW(g.configPath, base, 512);
    AppendW(g.configPath, L"\\VirtualCoinMonitor", 512);
    CreateDirectoryW(g.configPath, NULL);
    AppendW(g.configPath, L"\\state.ini", 512);
}

static int ReadAllFileW(const wchar_t* path, char* buf, int cap) {
    if (cap <= 0) return 0;
    buf[0] = 0;
    HANDLE f = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (f == INVALID_HANDLE_VALUE) return 0;
    DWORD got=0; BOOL ok = ReadFile(f, buf, (DWORD)(cap-1), &got, NULL); CloseHandle(f);
    if (!ok) return 0;
    buf[got] = 0;
    return (int)got;
}
static void WriteAllFileW(const wchar_t* path, const char* buf) {
    HANDLE f = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (f == INVALID_HANDLE_VALUE) return;
    DWORD wr=0; WriteFile(f, buf, (DWORD)strlen(buf), &wr, NULL); CloseHandle(f);
}
static int IniInt(const char* data, const char* key, int def) {
    char pattern[64]; sprintf(pattern, "%s=", key);
    char* p = strstr(data, pattern); if (!p) return def;
    p += strlen(pattern); return atoi(p);
}
static void IniStrW(const char* data, const char* key, wchar_t* out, int cap) {
    out[0]=0;
    char pattern[64]; sprintf(pattern, "%s=", key);
    char* p = strstr(data, pattern); if(!p) return;
    p += strlen(pattern);
    char tmp[256]; int i=0;
    while(p[i] && p[i]!='\r' && p[i]!='\n' && i<255) { tmp[i]=p[i]; ++i; }
    tmp[i]=0; CharToWide(tmp, out, cap);
}
static void LoadState() {
    BuildConfigPath();
    g.x=120; g.y=120; g.w=360; g.h=160; g.symbol=0; g.mode=0; g.locked=1; g.opacity=92; g.autostart=0;
    g.lastPrice=0; g.prevPrice=0; g.percent=0; g.high24=0; g.low24=0; g.volume24=0; g.histCount=0;
    CopyW(g.customApiSymbol, L"DOGEUSDT", 64); CopyW(g.customDisplay, L"DOGE", 64); g.customUseSpot=0;
    CopyA(g.status, "waiting for first refresh...", 128);
    char data[2048];
    if (ReadAllFileW(g.configPath, data, sizeof(data)) > 0) {
        g.x = IniInt(data, "x", g.x); g.y = IniInt(data, "y", g.y); g.w = IniInt(data, "w", g.w); g.h = IniInt(data, "h", g.h);
        g.symbol = IniInt(data, "symbol", g.symbol); g.mode = IniInt(data, "mode", g.mode); g.locked = IniInt(data, "locked", g.locked);
        g.opacity = IniInt(data, "opacity", g.opacity); g.autostart = IniInt(data, "autostart", g.autostart);
        IniStrW(data, "proxy", g.proxy, 256);
        IniStrW(data, "customApiSymbol", g.customApiSymbol, 64);
        IniStrW(data, "customDisplay", g.customDisplay, 64);
        g.customUseSpot = IniInt(data, "customUseSpot", g.customUseSpot);
        if (g.customApiSymbol[0] == 0) CopyW(g.customApiSymbol, L"DOGEUSDT", 64);
        if (g.customDisplay[0] == 0) StripQuoteSuffixW(g.customApiSymbol, g.customDisplay, 64);
    }
    if (g.symbol < 0 || g.symbol > kCustomSymbolIndex) g.symbol=0;
    if (g.mode < 0 || g.mode > 1) g.mode=0;
    if (g.opacity < 30) g.opacity=30; if (g.opacity>100) g.opacity=100;
    if (g.w < 1) g.w=360; if (g.h < 1) g.h=160;
}
static void SaveState() {
    RECT r; if (g.hwnd && GetWindowRect(g.hwnd, &r)) { g.x=r.left; g.y=r.top; g.w=r.right-r.left; g.h=r.bottom-r.top; }
    char proxyA[256]; WideToChar(g.proxy, proxyA, 256);
    char customApiA[96]; WideToChar(g.customApiSymbol, customApiA, 96);
    char customDisplayA[96]; WideToChar(g.customDisplay, customDisplayA, 96);
    char data[2048];
    _snprintf(data, sizeof(data), "x=%d\ny=%d\nw=%d\nh=%d\nsymbol=%d\nmode=%d\nlocked=%d\nopacity=%d\nautostart=%d\nproxy=%s\ncustomApiSymbol=%s\ncustomDisplay=%s\ncustomUseSpot=%d\n",
              g.x,g.y,g.w,g.h,g.symbol,g.mode,g.locked,g.opacity,g.autostart,proxyA,customApiA,customDisplayA,g.customUseSpot);
    WriteAllFileW(g.configPath, data);
}

static void ApplyOpacity() {
    BYTE alpha = (BYTE)(255 * g.opacity / 100);
    SetLayeredWindowAttributes(g.hwnd, 0, alpha, LWA_ALPHA);
}

static void ApplyLockedStyle() {
    if (!g.hwnd) return;
    LONG ex = GetWindowLongW(g.hwnd, GWL_EXSTYLE);
    ex |= WS_EX_LAYERED | WS_EX_TOOLWINDOW;
    if (g.locked) ex |= WS_EX_TRANSPARENT;
    else ex &= ~WS_EX_TRANSPARENT;
    SetWindowLongW(g.hwnd, GWL_EXSTYLE, ex);
    ApplyOpacity();
}

static int JsonGetString(const char* json, const char* key, char* out, int cap) {
    out[0]=0;
    char pattern[64]; sprintf(pattern, "\"%s\"", key);
    char* p = strstr(json, pattern); if(!p) return 0;
    p = strchr(p, ':'); if(!p) return 0;
    p++;
    while(*p==' ' || *p=='\t') p++;
    if(*p=='\"') p++;
    int i=0;
    while(*p && *p!='\"' && *p!='\r' && *p!='\n' && *p!=',' && *p!='}' && i<cap-1) out[i++]=*p++;
    out[i]=0;
    return i>0;
}

static int HttpGet(const wchar_t* host, const wchar_t* path, char* out, int outCap) {
    out[0]=0;
    // Use Windows system proxy / automatic proxy. No manual --proxy argument is needed.
    HINTERNET hs = WinHttpOpen(L"VirtualCoinMonitor/1.0", WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY,
                               WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if(!hs) {
        hs = WinHttpOpen(L"VirtualCoinMonitor/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                         WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    }
    if(!hs) { CopyA(g.status, "WinHttpOpen failed", 128); return 0; }
    WinHttpSetTimeouts(hs, 2500, 2500, 2500, 5000);
    HINTERNET hc = WinHttpConnect(hs, host, INTERNET_DEFAULT_HTTPS_PORT, 0);
    if(!hc) { WinHttpCloseHandle(hs); CopyA(g.status, "WinHttpConnect failed", 128); return 0; }
    HINTERNET hr = WinHttpOpenRequest(hc, L"GET", path, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);
    if(!hr) { WinHttpCloseHandle(hc); WinHttpCloseHandle(hs); CopyA(g.status, "WinHttpOpenRequest failed", 128); return 0; }
    int ok = 0;
    if (WinHttpSendRequest(hr, NULL, 0, NULL, 0, 0, 0) && WinHttpReceiveResponse(hr, NULL)) {
        DWORD total = 0;
        for (;;) {
            DWORD avail=0; if(!WinHttpQueryDataAvailable(hr, &avail) || avail==0) break;
            if (total + avail >= (DWORD)(outCap-1)) avail = (DWORD)(outCap-1-total);
            DWORD read=0; if(avail && WinHttpReadData(hr, out+total, avail, &read)) { total += read; }
            if (read == 0 || total >= (DWORD)(outCap-1)) break;
        }
        out[total]=0; ok = total > 0;
    }
    WinHttpCloseHandle(hr); WinHttpCloseHandle(hc); WinHttpCloseHandle(hs);
    if(!ok) CopyA(g.status, "network request failed", 128);
    return ok;
}

static void PushCandle(double o, double h, double l, double c) {
    if (c <= 0) return;
    if (o <= 0) o = c;
    if (h <= 0) h = c;
    if (l <= 0) l = c;
    if (h < l) { double t = h; h = l; l = t; }
    if (g.histCount < 180) {
        int i = g.histCount++;
        g.histOpen[i] = o; g.histHigh[i] = h; g.histLow[i] = l; g.histClose[i] = c; g.history[i] = c;
    } else {
        for(int i=1;i<180;i++) {
            g.histOpen[i-1]=g.histOpen[i]; g.histHigh[i-1]=g.histHigh[i];
            g.histLow[i-1]=g.histLow[i]; g.histClose[i-1]=g.histClose[i]; g.history[i-1]=g.history[i];
        }
        g.histOpen[179]=o; g.histHigh[179]=h; g.histLow[179]=l; g.histClose[179]=c; g.history[179]=c;
    }
}
static void PushPrice(double v) {
    if (v <= 0) return;
    if (g.histCount > 0) {
        int i = g.histCount - 1;
        if (g.histOpen[i] <= 0) g.histOpen[i] = v;
        if (v > g.histHigh[i]) g.histHigh[i] = v;
        if (g.histLow[i] <= 0 || v < g.histLow[i]) g.histLow[i] = v;
        g.histClose[i] = v; g.history[i] = v;
    } else {
        PushCandle(v, v, v, v);
    }
}

static int IsSpotSymbol() { return (g.symbol == ID_SYMBOL_XAU - ID_SYMBOL_BTC) || (g.symbol == kCustomSymbolIndex && g.customUseSpot); }
static const wchar_t* CurrentHost() { return IsSpotSymbol() ? kSpotHost : kFuturesHost; }
static const wchar_t* CurrentTickerPathPrefix() { return IsSpotSymbol() ? L"/api/v3/ticker/24hr?symbol=" : L"/fapi/v1/ticker/24hr?symbol="; }
static const wchar_t* CurrentKlinePathPrefix() { return IsSpotSymbol() ? L"/api/v3/klines?interval=1m&limit=120&symbol=" : L"/fapi/v1/klines?interval=1m&limit=120&symbol="; }
static const wchar_t* CurrentApiSymbol() { return (g.symbol == kCustomSymbolIndex) ? g.customApiSymbol : kApiSymbolsW[g.symbol]; }

static int FetchTicker() {
    wchar_t path[224]; CopyW(path, CurrentTickerPathPrefix(), 224); AppendW(path, CurrentApiSymbol(), 224);
    static char json[32768];
    if(!HttpGet(CurrentHost(), path, json, sizeof(json))) {
        if (g.symbol == kCustomSymbolIndex && !g.customUseSpot) {
            wchar_t spotPath[224]; CopyW(spotPath, L"/api/v3/ticker/24hr?symbol=", 224); AppendW(spotPath, CurrentApiSymbol(), 224);
            if (!HttpGet(kSpotHost, spotPath, json, sizeof(json))) return 0;
            g.customUseSpot = 1; SaveState();
        } else return 0;
    }
    char sLast[64], sPct[64], sHigh[64], sLow[64], sVol[64];
    if(!JsonGetString(json, "lastPrice", sLast, 64)) { CopyA(g.status, "bad ticker json", 128); return 0; }
    JsonGetString(json, "priceChangePercent", sPct, 64);
    JsonGetString(json, "highPrice", sHigh, 64);
    JsonGetString(json, "lowPrice", sLow, 64);
    JsonGetString(json, "volume", sVol, 64);
    char* end=0;
    g.prevPrice = g.lastPrice;
    g.lastPrice = strtod(sLast, &end);
    g.percent = strtod(sPct, &end);
    g.high24 = strtod(sHigh, &end);
    g.low24 = strtod(sLow, &end);
    g.volume24 = strtod(sVol, &end);
    PushPrice(g.lastPrice);
    CopyA(g.status, "online", 128);
    CopyA(g.lastUpdate, "updated", 64);
    return 1;
}

static int FetchKlines() {
    wchar_t path[224]; CopyW(path, CurrentKlinePathPrefix(), 224); AppendW(path, CurrentApiSymbol(), 224);
    static char json[65536];
    if(!HttpGet(CurrentHost(), path, json, sizeof(json))) {
        if (g.symbol == kCustomSymbolIndex && !g.customUseSpot) {
            wchar_t spotPath[224]; CopyW(spotPath, L"/api/v3/klines?interval=1m&limit=120&symbol=", 224); AppendW(spotPath, CurrentApiSymbol(), 224);
            if (!HttpGet(kSpotHost, spotPath, json, sizeof(json))) return 0;
            g.customUseSpot = 1; SaveState();
        } else return 0;
    }
    g.histCount = 0;
    char* p = json;
    while (*p && g.histCount < 120) {
        if (*p != '[') { p++; continue; }
        p++;
        int qIndex = 0;
        double o = 0, h = 0, l = 0, c = 0;
        while (*p && *p != ']') {
            if (*p == '"') {
                p++; qIndex++;
                char num[64]; int n=0;
                while(*p && *p != '"' && n<63) num[n++]=*p++;
                num[n]=0;
                char* e=0;
                double val = strtod(num, &e);
                if(qIndex == 1) o = val;
                else if(qIndex == 2) h = val;
                else if(qIndex == 3) l = val;
                else if(qIndex == 4) c = val;
            }
            if(*p) p++;
        }
        if(c > 0) PushCandle(o, h, l, c);
        if(*p) p++;
    }
    return g.histCount > 0;
}

static void RefreshData(int seedChart);

static LONG AtomicExchange(volatile LONG* p, LONG v) {
    return __atomic_exchange_n((LONG*)p, v, __ATOMIC_SEQ_CST);
}

static DWORD WINAPI RefreshWorkerProc(LPVOID) {
    int wantChart = (int)AtomicExchange(&g.pendingChart, 0);
    CopyA(g.status, "updating...", 128);
    if (g.hwnd) PostMessageW(g.hwnd, WM_DATA_READY, 0, 0);

    if (wantChart) FetchKlines();
    FetchTicker();

    int needAgain = (int)g.pendingChart;
    AtomicExchange(&g.fetching, 0);
    if (g.hwnd) PostMessageW(g.hwnd, WM_DATA_READY, 0, 0);
    if (needAgain) RefreshData(1);
    return 0;
}

static void RefreshData(int seedChart) {
    if (seedChart) AtomicExchange(&g.pendingChart, 1);
    if (AtomicExchange(&g.fetching, 1) == 0) {
        DWORD tid = 0;
        HANDLE th = CreateThread(NULL, 0, RefreshWorkerProc, NULL, 0, &tid);
        if (th) {
            CloseHandle(th);
        } else {
            AtomicExchange(&g.fetching, 0);
            if (seedChart) FetchKlines();
            FetchTicker();
            InvalidateRect(g.hwnd, NULL, false);
        }
    } else {
        CopyA(g.status, "updating...", 128);
        InvalidateRect(g.hwnd, NULL, false);
    }
}

static void SetAutoStart(int enable) {
    HKEY key=0; DWORD disp=0;
    if(RegCreateKeyExW(HKEY_CURRENT_USER, kRunKey, 0, NULL, 0, KEY_SET_VALUE|KEY_QUERY_VALUE, NULL, &key, &disp) != ERROR_SUCCESS) return;
    if(enable) {
        wchar_t exe[512]; ZeroMem(exe, sizeof(exe)); GetModuleFileNameW(NULL, exe, 512);
        RegSetValueExW(key, kRunValue, 0, REG_SZ, (const BYTE*)exe, (DWORD)((lstrlenW(exe)+1)*sizeof(wchar_t)));
        g.autostart=1;
    } else {
        RegDeleteValueW(key, kRunValue); g.autostart=0;
    }
    RegCloseKey(key); SaveState();
}

static HICON LoadAppIcon(HINSTANCE inst) {
    // Icon is embedded into the EXE as RT_GROUP_ICON/RT_ICON resource ID 1.
    HICON ico = (HICON)LoadImageW(inst, IDI_APPICON, IMAGE_ICON, 0, 0, LR_DEFAULTSIZE);
    if (!ico) ico = LoadIconW(inst, IDI_APPICON);
    if (!ico) ico = LoadIconW(NULL, IDI_APPLICATION);
    return ico;
}

static void AddTrayIcon(int add) {
    NOTIFYICONDATAW nid; ZeroMem(&nid, sizeof(nid));
    nid.cbSize = sizeof(nid); nid.hWnd = g.hwnd; nid.uID = 1;
    nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; nid.uCallbackMessage = WM_TRAYICON;
    nid.hIcon = g.appIcon ? g.appIcon : LoadIconW(NULL, IDI_APPLICATION);
    CopyW(nid.szTip, L"虚拟币监控 1.0", 128);
    Shell_NotifyIconW(add ? NIM_ADD : NIM_DELETE, &nid);
}

static void DrawTextIn(HDC dc, const char* text, RECT rc, UINT flags, COLORREF color, HFONT font) {
    HGDIOBJ old = SelectObject(dc, font);
    SetBkMode(dc, TRANSPARENT);
    SetTextColor(dc, color);
    DrawTextA(dc, text, -1, &rc, flags);
    SelectObject(dc, old);
}

static int PriceDecimals(double v) {
    if (v >= 1000.0) return 1;
    if (v >= 1.0) return 2;
    if (v >= 0.1) return 4;
    if (v >= 0.01) return 5;
    if (v >= 0.001) return 7;      // 1000PEPE 等小数价格，避免 0.00
    if (v >= 0.0001) return 8;
    if (v >= 0.00001) return 9;
    return 10;
}

static void FormatFixedPriceText(char* out, int cap, double v, int decimals) {
    if (!out || cap <= 0) return;
    out[0] = 0;
    if (v <= 0) { CopyA(out, "--", cap); return; }
    if (decimals < 0) decimals = 0;
    if (decimals > 10) decimals = 10;
    char fmt[16];
    sprintf(fmt, "%%.%df", decimals);
    char tmp[96];
    sprintf(tmp, fmt, v);
    char* dot = strchr(tmp, '.');
    int intLen = dot ? (int)(dot - tmp) : (int)strlen(tmp);
    int outPos = 0;
    for (int i = 0; i < intLen && outPos < cap - 1; ++i) {
        out[outPos++] = tmp[i];
        int left = intLen - i - 1;
        if (left > 0 && left % 3 == 0 && outPos < cap - 1) out[outPos++] = ',';
    }
    if (dot) {
        for (int i = intLen; tmp[i] && outPos < cap - 1; ++i) out[outPos++] = tmp[i];
    }
    out[outPos] = 0;
}

static void FormatPriceText(char* out, int cap, double v) {
    if (!out || cap <= 0) return;
    out[0] = 0;
    if (v <= 0) { CopyA(out, "--", cap); return; }
    FormatFixedPriceText(out, cap, v, PriceDecimals(v));
    char* dot0 = strchr(out, '.');
    if (dot0) {
        int len = (int)strlen(out);
        while (len > 0 && out[len-1] == '0') out[--len] = 0;
        if (len > 0 && out[len-1] == '.') out[--len] = 0;
    }
}

static int TextWidth(HDC dc, HFONT font, const char* text) {
    HGDIOBJ old = SelectObject(dc, font);
    SIZE_ sz; sz.cx = 0; sz.cy = 0;
    GetTextExtentPoint32A(dc, text, (int)strlen(text), &sz);
    SelectObject(dc, old);
    return (int)sz.cx;
}
static double FloorD(double v) { long long i = (long long)v; if ((double)i > v) --i; return (double)i; }
static double CeilD(double v) { long long i = (long long)v; if ((double)i < v) ++i; return (double)i; }
static double Pow10Floor(double v) {
    double p = 1.0;
    if (v <= 0.0) return 1.0;
    while (p * 10.0 <= v) p *= 10.0;
    while (p > v) p /= 10.0;
    return p;
}
static int MakeNiceTicks(double minv, double maxv, double* ticks, int maxTicks) {
    if (maxTicks < 2) return 0;
    double span = maxv - minv;
    if (span <= 0.0) { ticks[0]=minv; ticks[1]=maxv; return 2; }
    double rough = span / 5.0;
    double pow10 = Pow10Floor(rough);
    double candidates[5] = {1.0*pow10, 2.0*pow10, 2.5*pow10, 5.0*pow10, 10.0*pow10};
    double best = candidates[0];
    double bestErr = 999999.0;
    for (int i=0;i<5;i++) {
        double n = CeilD(maxv / candidates[i]) - FloorD(minv / candidates[i]);
        double err = AbsD(n - 5.0);
        if (err < bestErr) { bestErr = err; best = candidates[i]; }
    }
    double startTick = FloorD(minv / best) * best;
    double endTick = CeilD(maxv / best) * best;
    int n = 0;
    for (double v = startTick; v <= endTick + best * 0.1 && n < maxTicks; v += best) ticks[n++] = v;
    return n;
}

static int ClampI(int v, int lo, int hi) { if (v < lo) return lo; if (v > hi) return hi; return v; }

static void DrawChart(HDC dc, RECT rc) {
    if (g.histCount < 2) return;

    int count = g.histCount;
    int startIdx = count > 60 ? count - 60 : 0;
    int nBars = count - startIdx;

    double mn = g.histLow[startIdx], mx = g.histHigh[startIdx];
    for (int i = startIdx + 1; i < count; i++) {
        if (g.histLow[i] < mn) mn = g.histLow[i];
        if (g.histHigh[i] > mx) mx = g.histHigh[i];
    }
    if (AbsD(mx - mn) < 0.0000001) { mx += 1.0; mn -= 1.0; }
    double pad = (mx - mn) * 0.08;
    mn -= pad; mx += pad;

    COLORREF bgAxis  = RGB_(22, 27, 38);
    COLORREF gridCol = RGB_(38, 43, 54);
    COLORREF axisText= RGB_(122, 128, 142);
    COLORREF upCol   = RGB_(34, 171, 148);
    COLORREF downCol = RGB_(242, 54, 69);
    COLORREF sepCol  = RGB_(48, 54, 68);

    HFONT tickFont = CreateFontA(14,0,0,0,FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"Segoe UI");
    char sample[64]; FormatPriceText(sample, 64, mx);
    int labelTextW = TextWidth(dc, tickFont, sample);
    int labelH = 22;
    int gutter = MaxI(labelTextW + 22, 78);

    int plotX = rc.left;
    int plotY = rc.top;
    int plotW = MaxI(1, (rc.right - rc.left) - gutter);
    int plotH = MaxI(1, rc.bottom - rc.top);

    // Right price-axis background.
    HBRUSH axisBrush = CreateSolidBrush(bgAxis);
    HGDIOBJ oldBrush = SelectObject(dc, axisBrush);
    HGDIOBJ axisPen = CreatePen(PS_SOLID, 1, bgAxis);
    HGDIOBJ oldPen = SelectObject(dc, axisPen);
    Rectangle(dc, plotX + plotW, plotY, rc.right + 1, rc.bottom + 1);
    SelectObject(dc, oldPen); DeleteObject(axisPen);
    SelectObject(dc, oldBrush); DeleteObject(axisBrush);

    // Grid + price interval labels are back; latest-price line/tag remains red/green only.
    HGDIOBJ gridPen = CreatePen(PS_SOLID, 1, gridCol);
    oldPen = SelectObject(dc, gridPen);
    int hLines = 5;
    for (int i = 0; i <= hLines; ++i) {
        int y = plotY + (plotH * i) / hLines;
        MoveToEx(dc, plotX, y, NULL); LineTo(dc, plotX + plotW, y);
    }
    int vLines = 5;
    for (int i = 0; i <= vLines; ++i) {
        int x = plotX + (plotW * i) / vLines;
        MoveToEx(dc, x, plotY, NULL); LineTo(dc, x, plotY + plotH);
    }
    SelectObject(dc, oldPen); DeleteObject(gridPen);

    HGDIOBJ sepPen = CreatePen(PS_SOLID, 1, sepCol);
    oldPen = SelectObject(dc, sepPen);
    MoveToEx(dc, plotX + plotW, plotY, NULL); LineTo(dc, plotX + plotW, rc.bottom);
    SelectObject(dc, oldPen); DeleteObject(sepPen);

    for (int i = 0; i <= hLines; ++i) {
        double ratio = 1.0 - ((double)i / (double)hLines);
        double v = mn + (mx - mn) * ratio;
        int y = plotY + (plotH * i) / hLines;
        char txt[64]; FormatPriceText(txt, 64, v);
        RECT tr = {plotX + plotW + 8, y - 10, rc.right - 4, y + 12};
        DrawTextIn(dc, txt, tr, DT_LEFT | DT_VCENTER | DT_SINGLELINE, axisText, tickFont);
    }

    int slotW = MaxI(4, plotW / MaxI(1, nBars));
    int candleGap = MaxI(1, slotW / 5);
    int bodyW = slotW - candleGap;
    if (bodyW < 4) bodyW = 4;
    if (bodyW > 9) bodyW = 9;
    if (bodyW >= slotW) bodyW = slotW - 1;
    int wickXAdjust = bodyW / 2;

    HGDIOBJ penUp = CreatePen(PS_SOLID, 1, upCol);
    HGDIOBJ penDown = CreatePen(PS_SOLID, 1, downCol);
    HBRUSH brushUp = CreateSolidBrush(upCol);
    HBRUSH brushDown = CreateSolidBrush(downCol);

    for (int bi = 0; bi < nBars; ++bi) {
        int i = startIdx + bi;
        double o = g.histOpen[i], h = g.histHigh[i], l = g.histLow[i], c = g.histClose[i];
        int openY  = plotY + (int)((double)plotH - ((o - mn) / (mx - mn)) * (double)(plotH - 2)) + 1;
        int closeY = plotY + (int)((double)plotH - ((c - mn) / (mx - mn)) * (double)(plotH - 2)) + 1;
        int highY  = plotY + (int)((double)plotH - ((h - mn) / (mx - mn)) * (double)(plotH - 2)) + 1;
        int lowY   = plotY + (int)((double)plotH - ((l - mn) / (mx - mn)) * (double)(plotH - 2)) + 1;
        int isUp = c >= o;
        HGDIOBJ pen = isUp ? penUp : penDown;
        HBRUSH brush = isUp ? brushUp : brushDown;
        HGDIOBJ oldp = SelectObject(dc, pen);
        int x0 = plotX + bi * slotW + MaxI(0, (slotW - bodyW) / 2);
        int cx = x0 + wickXAdjust;
        MoveToEx(dc, cx, highY, NULL); LineTo(dc, cx, lowY);
        HGDIOBJ oldb = SelectObject(dc, brush);
        int top = openY < closeY ? openY : closeY;
        int bh = AbsD((double)(closeY - openY)) < 2.0 ? 2 : (int)AbsD((double)(closeY - openY));
        Rectangle(dc, x0, top, x0 + bodyW, top + bh);
        SelectObject(dc, oldb);
        SelectObject(dc, oldp);
    }

    double lastClose = g.histClose[count - 1];
    double prevClose = count > 1 ? g.histClose[count - 2] : lastClose;
    COLORREF cmpColor = lastClose >= prevClose ? upCol : downCol;
    int yy = plotY + (int)((double)plotH - ((lastClose - mn) / (mx - mn)) * (double)(plotH - 2)) + 1;

    for (int x = plotX; x < plotX + plotW - 4; x += 8) {
        HGDIOBJ p = CreatePen(PS_SOLID, 1, cmpColor);
        HGDIOBJ old = SelectObject(dc, p);
        MoveToEx(dc, x, yy, NULL); LineTo(dc, MinI(x + 4, plotX + plotW - 1), yy);
        SelectObject(dc, old); DeleteObject(p);
    }

    char label[64]; FormatPriceText(label, 64, lastClose);
    int padX = 8;
    int liveLabelW = TextWidth(dc, tickFont, label) + padX * 2;
    int rx = plotX + plotW + 6;
    int ry = yy - labelH / 2;
    if (ry < rc.top + 2) ry = rc.top + 2;
    if (ry + labelH > rc.bottom - 2) ry = rc.bottom - 2 - labelH;
    HBRUSH labBrush = CreateSolidBrush(cmpColor);
    oldBrush = SelectObject(dc, labBrush);
    HGDIOBJ labPen = CreatePen(PS_SOLID, 1, cmpColor);
    oldPen = SelectObject(dc, labPen);
    RoundRect(dc, rx, ry, rx + liveLabelW, ry + labelH, 12, 12);
    SelectObject(dc, oldPen); DeleteObject(labPen);
    SelectObject(dc, oldBrush); DeleteObject(labBrush);
    RECT lr = {rx + padX, ry, rx + liveLabelW - 2, ry + labelH};
    DrawTextIn(dc, label, lr, DT_LEFT | DT_VCENTER | DT_SINGLELINE, RGB_(255,255,255), tickFont);

    DeleteObject(brushUp); DeleteObject(brushDown); DeleteObject(penUp); DeleteObject(penDown); DeleteObject(tickFont);
}

static int ClampFont(double v, int lo, int hi) {
    int r = (int)(v + 0.5);
    if (r < lo) r = lo;
    if (r > hi) r = hi;
    return r;
}

static void ApplyRoundRegion(HWND hwnd) {
    RECT wr; if (!GetWindowRect(hwnd, &wr)) return;
    int w = wr.right - wr.left;
    int h = wr.bottom - wr.top;
    HRGN rgn = CreateRoundRectRgn(0, 0, w + 1, h + 1, 24, 24);
    if (rgn) SetWindowRgn(hwnd, rgn, true);
}

static void OnPaint(HWND hwnd) {
    PAINTSTRUCT ps; HDC dc = BeginPaint(hwnd, &ps);
    RECT rc; GetClientRect(hwnd, &rc);

    COLORREF cardBg = (g.mode == MODE_CHART) ? RGB_(19, 23, 34) : RGB_(31, 35, 46);
    COLORREF border = (g.mode == MODE_CHART) ? RGB_(43, 48, 61) : RGB_(62, 66, 79);

    HBRUSH bg = CreateSolidBrush(cardBg);
    HGDIOBJ oldBrush = SelectObject(dc, bg);
    HGDIOBJ borderPen = CreatePen(PS_SOLID, 1, border);
    HGDIOBJ oldPen = SelectObject(dc, borderPen);
    RoundRect(dc, 0, 0, rc.right, rc.bottom, 24, 24);
    SelectObject(dc, oldPen); DeleteObject(borderPen);
    SelectObject(dc, oldBrush); DeleteObject(bg);

    RECT content = {8, 8, rc.right - 8, rc.bottom - 8};
    if (content.right < content.left) content.right = content.left;
    if (content.bottom < content.top) content.bottom = content.top;

    if (g.mode == MODE_PRICE) {
        int cw = content.right - content.left;
        int ch = content.bottom - content.top;
        int priceFs = ClampI(MinI((int)(cw * 0.20), (int)(ch * 0.60)), 22, 98);
        int changeFs = ClampI((int)(priceFs * 0.34), 14, 34);
        HFONT fontPrice = CreateFontA(priceFs,0,0,0,FW_BLACK,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"Segoe UI");
        HFONT fontChange = CreateFontA(changeFs,0,0,0,FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,"Segoe UI");

        char price[128]; FormatPriceText(price, 128, g.lastPrice);
        COLORREF pcol = RGB_(255,255,255);
        if (g.prevPrice > 0 && g.lastPrice > g.prevPrice) pcol = RGB_(34,171,148);
        else if (g.prevPrice > 0 && g.lastPrice < g.prevPrice) pcol = RGB_(242,54,69);

        int changeAreaH = changeFs + 20;
        int priceBottom = content.bottom - changeAreaH;
        RECT prc = {content.left + 2, content.top - 2, content.right - 2, priceBottom};
        DrawTextIn(dc, price, prc, DT_CENTER | DT_VCENTER | DT_SINGLELINE, pcol, fontPrice);

        char info[64];
        if (g.lastPrice > 0) sprintf(info, "%+.2f%%", g.percent); else CopyA(info, "--", 64);
        RECT irc = {content.left, priceBottom - 2, content.right, content.bottom + 2};
        COLORREF ccol = (g.lastPrice > 0) ? (g.percent >= 0 ? RGB_(34,171,148) : RGB_(242,54,69)) : RGB_(152,162,179);
        DrawTextIn(dc, info, irc, DT_CENTER | DT_VCENTER | DT_SINGLELINE, ccol, fontChange);

        DeleteObject(fontPrice); DeleteObject(fontChange);
    } else {
        DrawChart(dc, content);
    }

    if (!g.locked) {
        HGDIOBJ pen = CreatePen(PS_SOLID, 1, RGB_(90,100,114));
        HGDIOBJ old = SelectObject(dc, pen);
        MoveToEx(dc, rc.right-18, rc.bottom-7, NULL); LineTo(dc, rc.right-7, rc.bottom-18);
        MoveToEx(dc, rc.right-12, rc.bottom-7, NULL); LineTo(dc, rc.right-7, rc.bottom-12);
        SelectObject(dc, old); DeleteObject(pen);
    }
    EndPaint(hwnd, &ps);
}

static void AppendMenuChecked(HMENU m, UINT id, LPCWSTR text, int checked) {
    AppendMenuW(m, MF_STRING | (checked ? MF_CHECKED : MF_UNCHECKED), id, text);
}
static void ShowContextMenu(HWND hwnd) {
    HMENU m = CreatePopupMenu();

    HMENU sym = CreatePopupMenu();
    AppendMenuChecked(sym, ID_SYMBOL_BTC, L"BTC", g.symbol==0);
    AppendMenuChecked(sym, ID_SYMBOL_ETH, L"ETH", g.symbol==1);
    AppendMenuChecked(sym, ID_SYMBOL_BNB, L"BNB", g.symbol==2);
    AppendMenuChecked(sym, ID_SYMBOL_SOL, L"SOL", g.symbol==3);
    AppendMenuChecked(sym, ID_SYMBOL_LTC, L"LTC", g.symbol==4);
    AppendMenuChecked(sym, ID_SYMBOL_XAU, L"XAU", g.symbol==5);
    if (g.customDisplay[0]) {
        wchar_t customLabel[96]; CopyW(customLabel, L"自定义：", 96); AppendW(customLabel, g.customDisplay, 96);
        AppendMenuChecked(sym, ID_SYMBOL_CUSTOM, customLabel, g.symbol==kCustomSymbolIndex);
    }
    AppendMenuW(sym, MF_SEPARATOR, 0, NULL);
    AppendMenuW(sym, MF_STRING, ID_CUSTOM_INPUT, L"手动输入币种...");
    AppendMenuW(m, MF_POPUP, (unsigned long long)sym, L"币种");

    AppendMenuW(m, MF_SEPARATOR, 0, NULL);
    AppendMenuW(m, MF_STRING, ID_TOGGLE_MODE, g.mode==MODE_PRICE ? L"切换到K线模式" : L"切换到数字价格");
    AppendMenuW(m, MF_SEPARATOR, 0, NULL);
    AppendMenuChecked(m, ID_LOCK, g.locked ? L"解锁窗口" : L"锁定窗口", g.locked);
    AppendMenuChecked(m, ID_AUTOSTART, L"开机自启", g.autostart);

    HMENU opa = CreatePopupMenu();
    AppendMenuChecked(opa, ID_OPA_30, L"30%", g.opacity==30);
    AppendMenuChecked(opa, ID_OPA_50, L"50%", g.opacity==50);
    AppendMenuChecked(opa, ID_OPA_70, L"70%", g.opacity==70);
    AppendMenuChecked(opa, ID_OPA_90, L"90%", g.opacity==90);
    AppendMenuChecked(opa, ID_OPA_100, L"100%", g.opacity==100);
    AppendMenuW(m, MF_POPUP, (unsigned long long)opa, L"透明度");

    AppendMenuW(m, MF_SEPARATOR, 0, NULL);
    AppendMenuW(m, MF_STRING, ID_REFRESH, L"立即刷新");
    AppendMenuW(m, MF_STRING, ID_EXIT, L"退出");
    POINT p; GetCursorPos(&p); SetForegroundWindow(hwnd);
    UINT cmd = TrackPopupMenu(m, TPM_RIGHTBUTTON|TPM_RETURNCMD, p.x, p.y, 0, hwnd, NULL);
    DestroyMenu(m);
    if(cmd) {
        extern LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
        WndProc(hwnd, WM_COMMAND, cmd, 0);
    }
}

static void SetCustomSymbolFromText(const wchar_t* text) {
    NormalizeManualSymbol(text, g.customApiSymbol, 64, g.customDisplay, 64, &g.customUseSpot);
    g.symbol = kCustomSymbolIndex;
    g.histCount = 0;
    g.lastPrice = 0; g.prevPrice = 0; g.percent = 0;
    CopyA(g.status, "waiting for first refresh...", 128);
    SaveState();
    RefreshData(1);
    InvalidateRect(g.hwnd, NULL, false);
}

LRESULT CALLBACK InputWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_CREATE: {
        CreateWindowExW(0, L"STATIC", L"输入币种，例如 DOGE 或 DOGEUSDT：", WS_CHILD|WS_VISIBLE,
                        16, 14, 250, 22, hwnd, NULL, g.inst, NULL);
        wchar_t initial[64];
        if (g.symbol == kCustomSymbolIndex) CopyW(initial, g.customDisplay, 64);
        else CopyW(initial, kDisplayW[g.symbol], 64);
        g.inputEdit = CreateWindowExW(0, L"EDIT", initial, WS_CHILD|WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,
                                      16, 42, 250, 26, hwnd, NULL, g.inst, NULL);
        CreateWindowExW(0, L"BUTTON", L"确定", WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON,
                        72, 82, 72, 28, hwnd, (HMENU)(ULONGLONG)ID_INPUT_OK, g.inst, NULL);
        CreateWindowExW(0, L"BUTTON", L"取消", WS_CHILD|WS_VISIBLE,
                        156, 82, 72, 28, hwnd, (HMENU)(ULONGLONG)ID_INPUT_CANCEL, g.inst, NULL);
        SetFocus(g.inputEdit);
        return 0;
    }
    case WM_COMMAND: {
        UINT id = (UINT)LOWORD_(wp);
        if (id == ID_INPUT_OK) {
            wchar_t text[96]; ZeroMem(text, sizeof(text));
            GetWindowTextW(g.inputEdit, text, 96);
            SetCustomSymbolFromText(text);
            DestroyWindow(hwnd);
            return 0;
        }
        if (id == ID_INPUT_CANCEL) { DestroyWindow(hwnd); return 0; }
        break;
    }
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
    if(id >= ID_SYMBOL_BTC && id <= ID_SYMBOL_XAU) { g.symbol = (int)(id - ID_SYMBOL_BTC); g.histCount=0; g.lastPrice=0; g.prevPrice=0; g.percent=0; SaveState(); RefreshData(1); }
    else if(id == ID_SYMBOL_CUSTOM) { g.symbol = kCustomSymbolIndex; g.histCount=0; g.lastPrice=0; g.prevPrice=0; g.percent=0; SaveState(); RefreshData(1); }
    else if(id == ID_CUSTOM_INPUT) { ShowInputWindow(g.hwnd); }
    else if(id == ID_TOGGLE_MODE) { g.mode = (g.mode == MODE_PRICE) ? MODE_CHART : MODE_PRICE; SaveState(); if(g.mode==MODE_CHART && g.histCount<2) RefreshData(1); InvalidateRect(g.hwnd, NULL, false); }
    else if(id == ID_LOCK) { g.locked = !g.locked; ApplyLockedStyle(); SaveState(); InvalidateRect(g.hwnd, NULL, false); }
    else if(id == ID_AUTOSTART) { SetAutoStart(!g.autostart); }
    else if(id == ID_OPA_30 || id == ID_OPA_50 || id == ID_OPA_70 || id == ID_OPA_90 || id == ID_OPA_100) {
        int vals[] = {30,50,70,90,100}; g.opacity = vals[id - ID_OPA_30]; ApplyOpacity(); SaveState();
    }
    else if(id == ID_REFRESH) { RefreshData(g.mode==MODE_CHART); }
    else if(id == ID_EXIT) { DestroyWindow(g.hwnd); }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch(msg) {
    case WM_CREATE:
        g.hwnd = hwnd; ApplyLockedStyle(); ApplyRoundRegion(hwnd); AddTrayIcon(1); SetTimer(hwnd, TIMER_REFRESH, 5000, NULL); RefreshData(1); return 0;
    case WM_DATA_READY:
        InvalidateRect(hwnd, NULL, false); return 0;
    case WM_TIMER:
        if(wp == TIMER_REFRESH) RefreshData(g.mode==MODE_CHART ? 1 : 0); return 0;
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
