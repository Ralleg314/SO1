#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include "rw_pid.h"

int PIDsegons, PIDprincipal, PIDhores, fd;
int segons;
int inicio = 1;


void contador(){
  segons++;
  if(segons == 60){
    segons = 0;
    kill(PIDprincipal, SIGUSR2);
    kill(PIDhores, SIGCONT);
  }
}

void inicializacion(int signo){
  
  if(inicio){
    
    fd = open("segons.pid", O_RDONLY);
    PIDsegons = read_pid(fd);
    
    fd = open("principal.pid", O_RDONLY);
    PIDprincipal = read_pid(fd);
    
    fd = open("hores.pid", O_RDONLY);
    PIDhores = read_pid(fd);
    
    segons = 0;
    inicio = 0;
    
  }else if(!inicio){
    contador();
  }
}


int main(void){
    
  int fd;
  int i;
  i= getpid();
    
  fd = open("minuts.pid", O_WRONLY | O_CREAT);
  write_pid(fd,i);
  
  signal(SIGCONT, inicializacion);
  
  while(1){
    pause();
  }
  return 0;
}
