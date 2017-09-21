#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

void *thread(void *vargp);
volatile long cnt = 0;
sem_t mutex;

int main(int argc, char **argv)
{
	long niters;
	pthread_t tid1, tid2;
	if(sem_init(&mutex, 0, 1) != 0)
		printf("sem init failed !");	

	if(argc != 2)
	{
		printf("usage: %s <niters>\n", argv[0]);
		exit(0);
	}
	niters = atoi(argv[1]);

	if(0 != pthread_create(&tid1, NULL, thread, &niters))
	{	
		printf("create pthread failed ! \n");
	}
	if(0 != pthread_create(&tid2, NULL, thread, &niters))
	{	
		printf("create pthread failed ! \n");
	}
	if(pthread_join(tid1, NULL) || pthread_join(tid2, NULL))
	{
		printf("phtread join failed ! \n");
	}

	/*check value*/
	if((2*niters) != cnt)
		printf("BOOM! cnt = %ld\n", cnt);
	else
		printf("OK! cnt = %ld\n", cnt);

	return 0;
}

void *thread(void *vargp)
{
	long i, niters = *((long *)vargp);
	
	for(i=0; i<niters; i++)
	{
		sem_wait(&mutex);
			cnt++;
		sem_post(&mutex);
	}
}
