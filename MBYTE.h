#include <windows.h>
#include <stdlib.h>

#define PAYLOAD(name) void name (BOOL active)
#define HEAD if (!active) return
#define DESKTOP GetDesktopWindow()
#define ARRAYLEN(x) (sizeof(x)/sizeof(*x))

typedef struct {
	int X, Y;
} COOR;

PAYLOAD (invert_all);
PAYLOAD (draw_marjan);

void get_desk_size (int *w, int *h);
BOOL LoadImgB (LPCSTR file_name, HDC hWinDC, COOR wsize, COOR wcoor);
COOR get_hwnd_size (HWND hwnd);
COOR get_hwnd_coor (HWND hwnd);

extern void (*payloads[])(BOOL active);
