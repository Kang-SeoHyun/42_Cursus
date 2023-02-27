#include <unistd.h>

int main(int ac, char **av)
{
	int arr[256];
	int idx;

	if(ac == 3)
	{
		idx = 0;
		while(av[2][idx])
		{
			arr[(int)av[2][idx]] = 1;
			idx++;
		}
		idx = 0;
		while(av[1][idx])
		{
			if(arr[(int)av[1][idx]] == 1)
			{
				write(1, &av[1][idx] , 1);
				arr[(int)av[1][idx]] = 2;
			}
			idx++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
