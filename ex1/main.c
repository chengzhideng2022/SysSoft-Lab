#include <stdio.h>
#include <stdlib.h>
int main() {
	//	printf("Hello world\n");
	//	system("clear");
	//	system("ls -l > files.txt");
	//	system("sort files.txt | more");

	int sizeof_int = sizeof(int);
	printf("sizeof(int) = %d\n", sizeof_int);
	int sizeof_char = sizeof(char);
	printf("sizeof(char) = %d\n", sizeof_char);
	int sizeof_short = sizeof(short);
	printf("sizeof(short) = %d\n", sizeof_short);
	int sizeof_float = sizeof(float);
	printf("sizeof(float) = %d\n", sizeof_float);
	int sizeof_long = sizeof(long);
	printf("sizeof(long) = %d\n", sizeof_long);
	int sizeof_long_long = sizeof(long long);
	printf("sizeof(long long) = %d\n", sizeof_long_long);
	int sizeof_double = sizeof(double);
	printf("sizeof(double) = %d\n", sizeof_double);
	int sizeof_void = sizeof(void);
	printf("sizeof(void) = %d\n", sizeof_void);
	int sizeof_void_ptr = sizeof(void*);
	printf("sizeof(void*) = %d\n", sizeof_void_ptr);
	return 0;
}
