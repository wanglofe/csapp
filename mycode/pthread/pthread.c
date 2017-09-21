#include <stdio.h>
#include <pthread.h>

//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//		   void *(*start_routine) (void *), void *arg);

int OS_CREATE_THREAD(void *thread(void *arg), void *arg);
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

int OS_CREATE_THREAD (void *thread(void *pArg), void *arg)
{
	pthread_t tid;
	if( 0!= pthread_create(&tid, NULL, thread, arg) )
	{
		printf("Create thread failed ! \n ");
			return -1;
	}
	printf("tid: %u \n", (unsigned int)tid);
	return 0;
}
