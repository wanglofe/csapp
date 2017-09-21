#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;//initializer

void *pthread_1 (void *arg);
void *pthread_2 (void *arg);
volatile long long cnt = 0;

int main()
{
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, pthread_1, NULL);
	pthread_create(&tid2, NULL, pthread_2, NULL);
//	pthread_join(tid1, NULL);
//	pthread_join(tid2, NULL);
	pthread_detach(tid1);
	pthread_detach(tid2);
	sleep(1);
	printf("cnt: %lld\n", cnt);
	return 0;
}

void *pthread_1(void *arg)
{	
	pthread_mutex_lock(&g_mutex);
	for(int i=0; i< 5000; i++)
		cnt++;
	pthread_mutex_unlock(&g_mutex);
}

void *pthread_2(void *arg)
{
	pthread_mutex_lock(&g_mutex);
	for(int i=0; i< 5000; i++)
	cnt++;
	pthread_mutex_unlock(&g_mutex);
}


