#include "MBYTE.h"

int get_desktop_size (BOOL width) {
	RECT drect;
	GetWindowRect (DESKTOP, &drect);
	if (width == TRUE) return drect.right;
	else return drect.bottom;
}
