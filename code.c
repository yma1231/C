#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int isUniqueChars(const char *str);

int main(int argc, const char* argv[]) {
	int i, test;
	char *str;

	for (i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	test = isUniqueChars(argv[1]);
	printf("Result: %d\n", test);
	return 0;
}

int isUniqueChars(const char *str) {
	int i;
	char check[256];
	int len = strlen(str);
	for (i = 0; i < strlen(str); i++) {
		char c = str[i];
		if (check[c] == 1)
			return false;
		check[c] = 1;
	}
	return 1;
}
