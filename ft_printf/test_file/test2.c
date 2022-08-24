#include <stdio.h>

int main()
{
	int		result;

	result = printf("d: %d \n", 0xbd51d);
	printf("result: %d \n", result);
	result = printf("i: %i \n", 0xbd51d);
	printf("result: %d \n", result);
	printf("------------------my---------------\n");
	result = ft_printf("d: %d \n", 0xbd51d);
	printf("result: %d \n", result);
	result = ft_printf("i: %i \n", 0xbd51d);
	printf("result: %d \n", result);


	result = printf("c: %d \n", 'a');
	printf("result: %d \n", result);
	result = printf("s: %s \n", "abc");
	printf("result: %d \n", result);
	result = printf("p: %p \n", &result);
	printf("result: %d \n", result);
	result = printf("d: %d \n", 7);
	printf("result: %d \n", result);
	result = printf("i: %i \n", -25);
	printf("result: %d \n", result);
	result = printf("u: %u \n", 25);
	printf("result: %d \n", result);

	int i = 314;
	unsigned int j = -4294966982;
	result = printf("+d: %u \n", i);
	result = printf("-d: %u \n", j);
	printf("result: %d \n", result);



	result = printf("x: %x \n", 3144565464564544568);
	printf("result: %d \n", result);
	result = printf("X: %X \n", 3144565464564544568);
	printf("result: %d \n", result);
	result = ft_printf("x: %x \n", 3144565464564544568);
	printf("result: %d \n", result);
	result = ft_printf("X: %X \n", 3144565464564544568);
	printf("result: %d \n", result);

	result = printf("percent: %% \n");
	printf("result: %d \n", result);
	printf("-------------------------\n");
	printf("-------------------------\n");

	result = ft_printf("my c: %c \n", 'a');
	printf("result: %d \n", result);
	result = printf("my c: %c \n", 'a');
	printf("result: %d \n", result);
	printf("-------------------------\n");

	result = ft_printf("my s: %s \n", "\0");
	printf("result: %d \n", result);
	result = printf("my s: %s \n", "\0");
	printf("result: %d \n", result);
	printf("-------------------------\n2\n");
	result = ft_printf("my s: %s \n", "");
	printf("result: %d \n", result);
	result = printf("my s: %s \n", "");
	printf("result: %d \n", result);
	printf("-------------------------\n3\n");

	result = ft_printf("my s: %s \n", NULL);
	printf("result: %d \n", result);
	result = printf("my s: %s \n", NULL);
	printf("result: %d \n", result);
	printf("-------------------------\n");

	result = ft_printf("my %%: %% \n");
	printf("result: %d \n", result);
	result = printf("my %%: %% \n");
	printf("result: %d \n", result);
	printf("-------------------------\n");

	result = ft_printf("my c: %c \n", '\0');
	printf("result: %d \n", result);
	result = printf("my c: %c \n", '\0');
	printf("result: %d \n", result);
	printf("-------------------------\n2\n");
	result = ft_printf("my c: %c \n");
	printf("result: %d \n", result);
	result = printf("my c: %c \n");
	printf("result: %d \n", result);

int a;

a=1;
	result = ft_printf("my p: %p \n", &a);
	printf("result: %d \n", result);
	result = printf("my p: %p \n", &a);
	printf("result: %d \n", result);
	printf("-------------------------\n2\n");

	result = ft_printf("my c: %x \n", -310004);
	printf("result: %d \n", result);
	result = printf("my c: %x \n", -310004);
	printf("result: %d \n", result);
	printf("-------------------------\n2\n");
	result = ft_printf("my c: %X \n", -310004);
	printf("result: %d \n", result);
	result = printf("my c: %X \n", -310004);
	printf("result: %d \n", result);

}