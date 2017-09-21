#include <stdio.h>
#include <pthread.h>

#define  OS_CREATE_THREAD(thread, arg) 				\
do{								\
	pthread_t tid;						\
	if( 0!= pthread_create(&tid, NULL, thread, arg) )	\
	{							\
		printf("Create thread failed ! \n ");		\
	}							\
	printf("tid: %u \n", (unsigned int)tid);		\
}while (0)							

void *poweron_init(void *pArg);

int main ()
{
	for (int i=0; i<5; i++)	
		OS_CREATE_THREAD(poweron_init, NULL);
	return 0;
}

void *poweron_init(void *pArg)
{
	printf("Power on end ! \n");
	return 0;
}

