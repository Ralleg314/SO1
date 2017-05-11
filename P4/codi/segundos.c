#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include "rw_pid.h"

int PIDprincipal, PIDminuts, PIDhores, fd;

void inicializacion(int signo){

  fd = open("principal.pid", O_RDONLY, 0666);
  PIDprincipal = read_pid(fd);

  fd = open("minuts.pid", O_RDONLY, 0666);
  PIDminuts = read_pid(fd);
}

void contador(int signo){
// Cuando pasa 1 segundo avisamos a minutos y principal
  kill(PIDprincipal, SIGUSR1);
  kill(PIDminuts, SIGCONT);
}



int main(void){

  int i;
  i= getpid();
// Guardamos PID en un documento
  fd = open("segons.pid", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  write_pid(fd,i);

// Tratamos las señales
  signal(SIGCONT, inicializacion);
  signal(SIGALRM, contador);

// Bucle donde espera las señales
  while(1){
    pause();
// Saltara el pause() por primera vez en inicializarse
// y alarm() hara que salte las demas vezes enviandos
// la señal ALRM
    alarm(1);
  }
  return 0;
}
