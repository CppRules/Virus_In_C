#include "MBYTE.h"

BOOL CALLBACK EnumChildProc (HWND hwnd, LPARAM lParam);

PAYLOAD (invert_all) {
	HEAD;
	
	EnumChildWindows (DESKTOP, &EnumChildProc, NULL);
	return;
}

BOOL CALLBACK EnumChildProc (HWND hwnd, LPARAM lParam) {
	RECT aaa; 
	GetWindowRect (hwnd, &aaa);
	BitBlt(GetDC(hwnd), 0, 0, (aaa.right-aaa.left), (aaa.bottom-aaa.top), GetDC(DESKTOP), 0, 0, NOTSRCCOPY);
	
	return TRUE;
}
