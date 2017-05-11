#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include "rw_pid.h"

#define SIZE 100

int PIDsegons, PIDminuts, PIDhores;
int fd = -1;
int flag = 1;
int hh, mm, ss;


void inicializacion(int signo){
  if(fd == -1){

    fd = open("segons.pid", O_RDONLY, 0666);
    PIDsegons = read_pid(fd);

    fd = open("minuts.pid", O_RDONLY, 0666);
    PIDminuts = read_pid(fd);

    fd = open("hores.pid", O_RDONLY, 0666);
    PIDhores= read_pid(fd);

// Inicializa los otros procesos
    kill(PIDhores, SIGCONT);
    kill(PIDminuts, SIGCONT);
    kill(PIDsegons, SIGCONT);

  }else{
// Si ya tenemos el PID de los demas procesos contamos horas
// Mal funcionaminto si se llama a inicir_contador mas de una vez
    hh++;
  }
}

void countsec(){
// suma segundos +1
// si llega a 60 lo reinicia
  ss++;
  if(ss==60){
    ss=0;
  }
}
void countmin(){
// suma minutos +1
// si llega a 60 lo reinicia
  mm++;
  if(mm==60){
    mm=0;
  }
}

void finalizar(){

// Mata los procesos en orden de dependencia
    kill(PIDsegons, SIGTERM);
    kill(PIDminuts, SIGTERM);
    kill(PIDhores, SIGTERM);
    write(1, "reloj finalizado\n", 17);

// Rompe el bucle y para que termine el programa
    flag = 0;
//    kill(getpid(), SIGKILL);
}

void mostrar(){
  int len;
  char buffer[SIZE];
// Carga los valores de horas, minutos y segundos en el buffer
  sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);
  len = strlen(buffer);

// Muestra el buffer por consola/salida predeterminada
  write(1, buffer, len);
}

int main(void){

  int i;
  i = getpid();

// Guarda PID en un documento
  fd = open("principal.pid", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  write_pid(fd,i);

  //para usarlo como flag y ahorrarme una variable
  fd = -1;
// Trata todas las señales que recivira
  signal(SIGCONT, inicializacion);
  signal(SIGUSR1, countsec);
  signal(SIGUSR2, countmin);
  signal(SIGTERM, finalizar);
  signal(SIGALRM, mostrar);

// Bucle para captar señales
  while(flag){
    pause();
  }

  return 0;
}
