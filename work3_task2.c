#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

pid_t fork(void);

int main() {
pid_t pid;
pid = fork();
if (pid == -1) {
printf("answer: ERROR\n");
} else if (pid == 0) {
printf("answer: child\n");
} else {
printf("answer: parent\n"); }
return 0;
}
