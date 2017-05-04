#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include "rw_pid.h"

int PIDsegons, PIDminuts, PIDprincipal, fd;
int minuts;
int inicio = 1;


void contador(){
  minuts++;
  if(minuts == 60){
    minuts = 0;
    kill(PIDprincipal, SIGCONT);
  }
}

void inicializacion(int signo){
  
  if(inicio){
    
    fd = open("segons.pid", O_RDONLY);
    PIDsegons = read_pid(fd);
    
    fd = open("minuts.pid", O_RDONLY);
    PIDminuts = read_pid(fd);
    
    fd = open("principal.pid", O_RDONLY);
    PIDprincipal = read_pid(fd);
    
    minuts = 0;
    inicio = 0;
    
  }else if(!inicio){
    contador();
  }
}

int main(void){
    
  int fd;
  int i;
  i= getpid();
    
  fd = open("hores.pid", O_WRONLY | O_CREAT);
  write_pid(fd,i);
  
  signal(SIGCONT, inicializacion);
  
  while(1){
    pause();
  }
  return 0;
}
