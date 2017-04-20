#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void)
{
  int ret;
  int len;
  int hh, mm, ss;
  char buffer[SIZE];

  ss = 23;
  mm = 9;
  hh = 0;

  sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);

  len = strlen(buffer);
  write(1, buffer, len);
  ret=fork();
  if(ret==0){
	execv("horas");
  }

  ret=fork();
  if(ret==0){
        execv("minutos");
  }
  
  ret=fork();
  if(ret==0){
        execv("segundos");
  }
  wait(NULL);
  return 0;
}
