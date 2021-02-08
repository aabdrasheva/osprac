#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pid_t fork(void);

int main(int argc, char *argv[], char *envp[]) {
pid_t pid;
pid = fork();
if (pid == -1) {
	printf("answer: ERROR\n");
} else if (pid == 0) {
	printf("answer: child\n");
	(void) execle("/bin/cat", "/bin/cat", "lab4_task4.c", 0, envp);
	printf("ERROR\n");
	exit(-1);
} else {
	printf("answer: parent\n");}
return 0;
}
