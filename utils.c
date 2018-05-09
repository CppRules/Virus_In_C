#include "MBYTE.h"

COOR get_hwnd_size (HWND hwnd) {
	RECT rect;
	GetWindowRect (hwnd, &rect);
	COOR a;
	a.X = rect.right-rect.left;
	a.Y = rect.bottom-rect.top;
	return a;
}

COOR get_hwnd_coor (HWND hwnd) {
	RECT rect;
	GetWindowRect (hwnd, &rect);
	COOR a;
	a.X = rect.left;
	a.Y = rect.top;
	return a;
}

BOOL LoadImgB (LPCSTR file_name, HDC hWinDC, COOR wsize, COOR wcoor) {
	//load
	HBITMAP bitmap;
	bitmap = (HBITMAP)LoadImage(NULL, file_name, IMAGE_BITMAP,
	wsize.X, wsize.Y, LR_LOADFROMFILE);
	
	//was it loaded?
	if (bitmap == NULL) {
		return FALSE;
	}	
	
	//create compatible
	HDC ahdc;
	ahdc = CreateCompatibleDC(hWinDC);
	
	//verify again
	if (ahdc == NULL) {
		return FALSE;
	}
	
	BITMAP mapofbits;
	int retval = GetObject((HGDIOBJ)(bitmap), sizeof(BITMAP),
	(LPVOID)(&mapofbits));
	if (!retval) {
		return FALSE;
	}
	
	HBITMAP oldbmp = (HBITMAP)SelectObject(ahdc, bitmap);
	if (oldbmp == NULL) {
		return FALSE;
	}
	
	//blit
	BOOL get_blit = BitBlt(hWinDC, wcoor.X, wcoor.Y, mapofbits.bmWidth,
	mapofbits.bmHeight, ahdc, 0, 0, SRCCOPY);
	if (!get_blit) {
		return FALSE;
	}
	
	//unint
	SelectObject (ahdc, oldbmp);
	DeleteDC (ahdc);
	DeleteObject(bitmap);
	
	return TRUE;
}
