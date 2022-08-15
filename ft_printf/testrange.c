#include <stdio.h>

int main()
{

	printf("int의 크기 %d \n", sizeof(int));
	printf("long의 크기 %d \n", sizeof(long));
	printf("long long의 크기 %d \n", sizeof(long long));
	printf("long long의 크기 %d \n", sizeof(unsigned long));
	printf("long long의 크기 %d \n", sizeof(unsigned long long));
	printf("long long의 크기 %d \n", sizeof(unsigned long int));
	printf("long long의 크기 %d \n", sizeof(unsigned int));
	printf("long long의 크기 %d \n", sizeof(void *));

    return 0;
}