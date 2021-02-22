#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>

int res = 0;

int main() {
	int fd[2];
	size_t size = 1;
	char* resstring = malloc( sizeof(char));
	if (pipe(fd) < 0) {
		printf("Can't create pipe\n");
		exit(-1);
	}
	fcntl(fd[1], F_SETFL, fcntl(fd[1], F_GETFL) | O_NONBLOCK);
	while (size == 1) {
		size = write(fd[1], resstring, 1);
		res++;
	}
	printf("Result: %d\n", res);
	return 0;
}
