#include "philo.h"

int	ft_error(char *str)
{
	printf("ERROR : %s", str);
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 5 && argc != 6)
	{
		ft_error("argument count") //print err
		return (1);
	}
	if (parsing(&info, argc, argv) == -1)
		return (2);
	simulate(&info);
	return (0);
}