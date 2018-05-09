#include "MBYTE.h"

void (*payloads[])(BOOL active) = {
	&invert_all,
	&draw_marjan
};

int main (void) {
	int payloads_size = ARRAYLEN(payloads);
	int i;
	for (i = 0; i < payloads_size; i++) {
		(*payloads[i])(TRUE);
		if (i!=payloads_size-1) if (MessageBox(NULL, "continue?", "", MB_YESNO) != IDYES) break;	
	}
	return 0;
}
