#include <windows.h>

#define PAYLOAD(name) void name (BOOL active)
#define HEAD if (!active) return
#define DESKTOP GetDesktopWindow()

PAYLOAD (invert_all);
get_desktop_size (BOOL width);
