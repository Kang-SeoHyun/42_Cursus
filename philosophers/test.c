# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

void	print_done(pthread_mutex_t *m_print)
{
	pthread_mutex_lock(m_print);
	printf("successfully!\n");
	exit(0);
    printf("hihi exit locate error\n");
	pthread_mutex_unlock(m_print);
}

int main()
{
    pthread_mutex_t	m_print;

    pthread_mutex_init(&m_print, NULL);
    print_done(&m_print);
}