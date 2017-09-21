#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;
int i;
#define  OS_CREATE_THREAD(thread, arg) 				\
do{								\
	pthread_t tid ;						\
	if( 0!= pthread_create(&tid, NULL, thread, arg) )	\
	{							\
		printf("Create thread failed ! id: %d\n ", i);exit (1);		\
	}							\
	printf("tid: %u \n", (unsigned int)tid);		\
}while (0)							

void *poweron_init(void *pArg);

int main ()
{
	for ( i=0; i<1010; i++)	
	{
		pthread_mutex_lock(&g_mutex);
		OS_CREATE_THREAD(poweron_init, NULL);
		pthread_mutex_unlock(&g_mutex);
//		pthread_join(pthread_self(), NULL);
		pthread_detach(pthread_self());
		usleep(10000);
	}
	return 0;
}

void *poweron_init(void *pArg)
{
	printf("Power on end ! \n");
	return 0;
}

