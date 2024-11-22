#include <stdio.h>
#include <stdbool.h>

#define assert(x, y) if(!(x)) { printf("\n%s", y); return false; }