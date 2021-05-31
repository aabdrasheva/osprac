#include <signal.h>
#include <stdio.h>

void my_handler(int nsig) {
  if(nsig == SIGINT)
    printf(" signal, <CTRL> - <С> pressed\n");

  else if(nsig == SIGQUIT)
    printf(" signal, <CTRL> - <4> pressed\n");
}

int main(void) {

  (void)signal(SIGINT, my_handler);

  (void)signal(SIGQUIT, my_handler);

  while(1);

  return 0;
}
