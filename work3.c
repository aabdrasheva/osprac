#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

pid_t getpid(void);
pid_t getppid(void);

int main() {
printf("PID = %d, PPID = %d\n", getpid(), getppid());

return 0;
}
