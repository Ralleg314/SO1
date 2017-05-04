#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include "rw_pid.h"

int PIDprincipal, PIDminuts, PIDhores, fd;
  
void inicializacion(int signo){
  
  fd = open("principal.pid", O_RDONLY);
  PIDprincipal = read_pid(fd);
  
  fd = open("minuts.pid", O_RDONLY);
  PIDminuts = read_pid(fd);
  
  fd = open("hores.pid", O_RDONLY);
  PIDhores = read_pid(fd);
}

void contador(int signo){
  kill(PIDprincipal, SIGUSR1);
  kill(PIDminuts, SIGCONT);
}



int main(void){

  int i;
  i= getpid();
    
  fd = open("segons.pid", O_WRONLY | O_CREAT);
  write_pid(fd,i);
  
  signal(SIGCONT, inicializacion);
  signal(SIGALRM, contador);
  
  while(1){
    pause();
  }
  return 0;
}
