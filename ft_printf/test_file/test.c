#include <stdio.h>

int main()
{
	printf("c: %c ", NULL);
	printf("s: %s ", NULL);
	printf("d: %d ", -2147483649);
	printf("%i ", NULL);
	printf("%u ", NULL);
	printf("%x ", NULL);
	printf("%X ", NULL);
	printf("%p ", NULL);
	return 0;
}