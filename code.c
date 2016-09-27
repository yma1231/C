#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int isUniqueChars(const char *str);
int isUniqueChars2(const char *str);
int isUniqueChars3(const char *arr);
void reverse(const char *str);
void removeDupilicate(const char *str);

int main(int argc, const char* argv[]) {
	int i, test;

	for (i = 0; i < argc; i++) {
		int len = strlen(argv[i]);
		printf("argv[%d] = %s, len = %d\n", i, argv[i], len);
	}
	
	//test = isUniqueChars(argv[1]); /*1.1-1*/
	//test = isUniqueChars2(argv[1]); /*1.1-2*/
	//test = isUniqueChars3(argv[1]); /*1.1-3*/
	//reverse(argv[1]);
	removeDupilicate(argv[1]);
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

void reverse(const char *str) {
	int len = strlen(str);
	char *arr = malloc(sizeof(char) * len);
	char *arr_mark = arr;

	strcpy(arr, str);
	printf("string: %s\n", arr);
	char *end = arr;
	char temp;
	int i = 0;
	if (arr) {
		while (*end)
			end++;
		end--;
		
		while (arr < end) {
			temp = *arr;
			*arr = *end; 
			*end = temp;
			arr++;
			end--;
		}
	}
	printf("reverse string: %s\n", arr_mark);
	free(arr_mark);
}

void removeDupilicate(const char *str) {
	if (str == NULL) return;
	int len = strlen(str);
	if (len < 2) return;

	char *arr = (char *)malloc(sizeof(char) * len);
	if (arr == NULL)
		return;
	strcpy(arr, str);
	printf("string: %s\n", arr);

	int tail = 1, i;
	for (i = 1; i < len; i++) {
		int j;
		for (j = 0; j < tail; j++) {
			if (arr[i] == arr[j]) break; // j < tail
		}
		if (j == tail) {
			arr[tail] = arr[i];
			tail++;
		}
	printf("i: %d, j: %d, tail: %d\n", i, j, tail);
	}
	arr[tail] = 0;
	printf("new array is: %s\n", arr);
}
