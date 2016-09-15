#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int isUniqueChars(const char *str);
int isUniqueChars2(const char *str);
int isUniqueChars3(const char *arr);

int main(int argc, const char* argv[]) {
	int i, test;

	for (i = 0; i < argc; i++) {
		int len = strlen(argv[i]);
		printf("argv[%d] = %s, len = %d\n", i, argv[i], len);
	}
	
	//test = isUniqueChars(argv[1]); /*1.1-1*/
	//test = isUniqueChars2(argv[1]); /*1.1-2*/
	//test = isUniqueChars3(argv[1]); /*1.1-3*/
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


int isUniqueChars2(const char *str) {
	int i, j;
	int len = strlen(str);
	for (i = 0; i < len - 1; i++) {
		for (j = i+1 ; j < len; j++) {
			if (str[i] == str[j])
				return false;
		}
	}
	return true;
}

int isUniqueChars3(const char *arr){
	int i, val;
	for (i = 0; i < strlen(arr); i++){
		int index = arr[i] - 'a';
		if ((val & (1 << index)) > 0)
			return false; 
		val |= 1 << index;
	}
	return true;
}

