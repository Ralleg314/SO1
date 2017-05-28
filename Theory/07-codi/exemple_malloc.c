#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(void)
{
  unsigned long int mida, nelems, meitat, darrer;
  int *a;
  clock_t t1, t2;

  mida   = 17179869185;
  nelems = mida / sizeof(int); 

  printf("mida = %lu   nelems = %lu\n", mida,nelems);

  t1 = clock();
  
  a = malloc(mida);

  if (!a)
  {
    printf("No he pogut ubicar la memoria.\n");
    exit(1);
  }
 
  darrer = nelems - 1;
  meitat = nelems / 2;

  a[0]      = 10;
  a[meitat] = 15;
  a[darrer] = 20;

  printf("a[0] = %d\n", a[0]);
  printf("a[%lu] = %d\n", meitat, a[meitat]);
  printf("a[%lu] = %d\n", darrer, a[darrer]);
  
  free(a);
}


