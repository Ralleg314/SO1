#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include "rw_pid.h"

int PIDsegons, PIDminuts, PIDprincipal;
int fd = -1;
int minuts;


void contador(){
// Suma +1 a los minutos contados
  minuts++;
// Si llevamos 60 minutos
  if(minuts == 60){
// Reinicia la cuenta y avisa de que ha pasado 1 hora
    minuts = 0;
    kill(PIDprincipal, SIGCONT);
  }
}

void inicializacion(int signo){

  if(fd == -1){
// Guarda PID del principal
    fd = open("principal.pid", O_RDONLY, 0666);
    PIDprincipal = read_pid(fd);
// Inicializa minutos
    minuts = 0;

  }else{
//ya tenemos el PID, contamos minutos hasta llegar a la hora
    contador();
  }
}

int main(void){

  int i;
  i= getpid();
// Guardamos e PID en un documneto
  fd = open("hores.pid", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  write_pid(fd,i);

  //lo uso de flag
  fd = -1;
// Tratamos la señal
  signal(SIGCONT, inicializacion);

// Bucle para mantenerlo abierto
  while(1){
    pause();
  }
  return 0;
}
