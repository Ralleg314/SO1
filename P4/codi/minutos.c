#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include "rw_pid.h"

int PIDsegons, PIDprincipal, PIDhores;
int fd = -1;
int segons;


void contador(){
// Cuenta segundos +1
  segons++;
  if(segons == 60){
// Si llevamos 60 segundos avisa de que ha pasado 1 minuto a horas y principal
    segons = 0;
    kill(PIDprincipal, SIGUSR2);
    kill(PIDhores, SIGCONT);
  }
}

void inicializacion(int signo){

  if(fd == -1){

    fd = open("principal.pid", O_RDONLY, 0666);
    PIDprincipal = read_pid(fd);

    fd = open("hores.pid", O_RDONLY, 0666);
    PIDhores = read_pid(fd);
// Inicializo segundos
    segons = 0;

  }else{
// Si ya tenemos los PID contamos
    contador();
  }
}


int main(void){

  int i;
  i= getpid();
// Guardamos el PID en un documneto
  fd = open("minuts.pid", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  write_pid(fd,i);

  //lo uso de flag
  fd = -1;
// Tratamos la señal
  signal(SIGCONT, inicializacion);

// Bucle para esperar la señal
  while(1){
    pause();
  }
  return 0;
}
