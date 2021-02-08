#include <stdio.h>
int main (int argc, char * argv[], char * envp[]) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("argv argument %d: %s\n", i, argv[i]);
	}
	int j = 0;
	while (envp[j] != NULL) {
		printf("enpv argument %d: %s\n", j, envp[j]);
		j++;
	}
	printf("enpv argument %d: %s\n", j, envp[j]);
	return 0;
}
