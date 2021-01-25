#include <stdlib.h>
#include <stdio.h>
int getuid();
int getgid();
int main() {

	printf("user ID = %d\n", getuid());
	printf("user GROUP = %d\n", getgid());
	return 0;
}
