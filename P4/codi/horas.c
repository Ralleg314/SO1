#include <stdio.h>

#include "rw_pid.h"

int main(void){
	int ret=getpid();
	printf("%d-", ret);
	foo();
	return 0;
}
