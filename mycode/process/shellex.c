#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAXLINE 100

int verbose = 0;
#define debugmsg(msg)			\
do{					\
	if(verbose == 1)		\
		printf("%s \n", msg);	\
}while(0)

int recv_cmd(void);
int parse_cmd (char *cmdline);
int eval (char *cmdline);

char *cmdlist[] = {
	"quit",
	NULL
};

void quit (void);
void (*funclist[]) (void)= {
	quit,
	NULL
};


//char *cmdline;//segment dumped??
char cmdline[100];
int main (int argc, char **argv)
{
	if (argc == 2 && strcmp(argv[1], "-v") == 0 )
		verbose = 1;

	while (1)
	{
		printf("@");

		if(recv_cmd())	continue;

		eval(cmdline);
	}

	return 0;
}

int recv_cmd(void)
{
	int retval = 0;

	memset(cmdline, 0, sizeof(cmdline));
	fgets(cmdline, MAXLINE, stdin);
	
	int i = 0;
	while ( cmdline[i] != '\0' && isspace(cmdline[i])) i++;
	if( cmdline[i] == '\0' ) retval = 1;

	return retval;
}

int eval (char *cmdline)
{	
	parse_cmd (cmdline);
	debugmsg("eval success ! \n");
	return 0;
}

int parse_cmd (char *cmdline)
{	
	int i;
	for (i=0; cmdlist[i]!=NULL; i++)
		while (strncmp(cmdline, cmdlist[i], sizeof(cmdlist[i])) == 0)//strncmp: '\n' in input str.
			funclist[i]();
	return 0;
}

void quit(void)
{
	debugmsg("quit! \n");
	exit(0) ;
}
