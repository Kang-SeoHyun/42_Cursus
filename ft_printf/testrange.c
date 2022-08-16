#include <stdio.h>

int main()
{

	printf("int의 크기 %d \n", sizeof(int));
	printf("long의 크기 %d \n", sizeof(long));
	printf("long long의 크기 %d \n", sizeof(long long));
	printf("unsigned long의 크기 %d \n", sizeof(unsigned long));
	printf("unsigned long long의 크기 %d \n", sizeof(unsigned long long));
	printf("unsigned long int의 크기 %d \n", sizeof(unsigned long int));
	printf("unsigned int의 크기 %d \n", sizeof(unsigned int));
	printf("void *의 크기 %d \n", sizeof(void *));
	printf("char *의 크기 %d \n", sizeof(char *));
	printf("int *의 크기 %d \n", sizeof(int *));
	printf("size_t의 크기 %d \n", sizeof(size_t));

    return 0;
}