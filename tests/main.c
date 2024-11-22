#include "test.h"

void test_func(bool (*fun_ptr)(), const char* function_name) {
	printf("Testing \033[1;33m%s\033[0m ...", function_name);
	if (fun_ptr()) {
		printf(" \033[1;32mpassed\033[0m\n");
	} else {
		printf(" ... \033[1;31mfailed\033[0m\n");
	}
}

int main() {
	printf("No tests implemented\n");
	return 0;
}
