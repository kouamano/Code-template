#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void SigCatch(int sig){
	fprintf(stderr,"SIGSEGV\n");
	exit(0);
};

int main(void){
	int *a;
	signal(SIGSEGV,SigCatch);
	a[1000000000] = 1;
}
