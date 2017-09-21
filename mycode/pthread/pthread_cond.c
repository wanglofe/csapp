#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define forever 1
volatile int flag = 0;
void *consumer(void *arg);
void *producter(void *arg);

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_cond = PTHREAD_COND_INITIALIZER;

int main ()
{	
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, producter, NULL);
	pthread_create(&tid2, NULL, consumer, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	return 0;
}

void *consumer(void *arg)
{
	pthread_mutex_lock(&g_mutex);
	
	while(forever)
	{
	printf("Consumer !\n");
		sleep(1);
		if(flag == 0)
		{	
			printf("No product ready ! continue wait ...\n");
		}
		else
		{
			printf("Get product now !\n");
		}
	}
	pthread_mutex_unlock(&g_mutex);
		
}

void *producter(void *arg)
{
	pthread_mutex_lock(&g_mutex);
	while(forever)
	{	
	printf("Producter !\n");
		flag = 0;
		sleep(4);
		flag = 1;
	}
	pthread_mutex_unlock(&g_mutex);
}
