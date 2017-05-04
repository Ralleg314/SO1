#include <unistd.h>

void write_pid(int fd,int pid){
	if(fd==-1){
		write(2,"Error\n",6);
	}else{
		write(fd, &pid, sizeof(pid));
		close(fd);
	}
}

int read_pid(int fd){
	int pid;
	if(fd==-1){		
		write(2,"Error\n",6);
		pid=-1;
	}else{
		read(fd, &pid, sizeof(pid));
		close(fd);
	}
	return pid;
}
