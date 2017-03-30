#include <stdio.h>
#include <unistd.h>

int main(void)
{
  fprintf(stderr, "PID: %d\n", getpid());
  fprintf(stdout, "Hola\n");
  fflush(stdout);

  getc(stdin);
  return 0;
}
