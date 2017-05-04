#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include "rw_pid.h"

#define SIZE 100

int PIDsegons, PIDminuts, PIDhores, fd;
int hh, mm, ss;
int inicio = 1;
int flag=1;


void inicializacion(int signo){
  if(inicio){
    
    fd = open("segons.pid", O_RDONLY);
    PIDsegons = read_pid(fd);
    
    fd = open("minuts.pid", O_RDONLY);
    PIDminuts = read_pid(fd);
    
    fd = open("hores.pid", O_RDONLY);
    PIDhores= read_pid(fd);
      
    kill(PIDhores, SIGCONT);
    kill(PIDminuts, SIGCONT);
    kill(PIDsegons, SIGCONT);
    
    inicio = 0;
    
  }else if(!inicio){
    hh++;
  }
}

void countsec(){
  ss++;
  if(ss==60){
    ss=0;
  }
}
void countmin(){
  mm++;
  if(mm==60){
    mm=0;
  }
}

void finalizar(){
    //salida del bucle
    flag=0;
    
    //mata los procesos en orden de dependencia
    kill(PIDsegons, SIGTERM);
    kill(PIDminuts, SIGTERM);
    kill(PIDhores, SIGTERM);
    write(1, "reloj finalizado\n", 17);
    //el programa por algun motivo ignora el flag
    kill(getpid(), SIGKILL);
}

void mostrar(){
  int len;
  char buffer[SIZE];
  
  sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);

  len = strlen(buffer);
  write(1, buffer, len);
}

int main(void){
  
  int i;
  i = getpid();
    
  fd = open("principal.pid", O_WRONLY | O_CREAT);
  write_pid(fd,i);
  
  signal(SIGCONT, inicializacion);
  signal(SIGUSR1, countsec);
  signal(SIGUSR2, countmin);
  signal(SIGTERM, finalizar);
  signal(SIGALRM, mostrar);
  
  pause();
  while(flag){
  }

  return 0;
}