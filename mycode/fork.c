#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
pid_t Fork(void);

int main()
{
	pid_t pid;
	int x = 1;
	
	pid = Fork();
	if(pid == 0)
	{
		printf("child: x = %d, pid = %d, ppid = %d.\n", ++x, getpid(), getppid());
		exit(0);
	}
	
	printf("parent: x = %d, pid = %d.\n", --x, getpid());
	exit(0);
//	return 0;
}
