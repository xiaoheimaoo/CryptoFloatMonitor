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
