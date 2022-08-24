#include <stdio.h>

int	main()
{
	printf("c: %#c ", 'a');
	printf("s: %#s ", "abcd");
	printf("d: %#d ", -123);
	printf("%#i ", -123);
	printf("%#u ", 123);
	printf("%#x ", 31);
	printf("%#X ", 31);
	printf("%#p ", NULL);
	return 0;
}