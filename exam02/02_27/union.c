#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int j;
	char arr[256] = {0, };

	if(ac == 3)
	{
		i = 1;
		while(i < 3)
		{
			j = 0;
			while(av[i][j])
			{
				if(arr[(int)av[i][j]] == 0)
				{
					write(1, &av[i][j], 1);
					arr[(int)av[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
