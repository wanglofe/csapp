#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t Fork(void)
{
	pid_t pid;
	if((pid = fork()) < 0)
	{
		printf("LINE: [%d], fork() error!",__LINE__);
	}

	return 0;
}
