#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1024

struct options {
	int help;
	int stat;
	int argint;
	char *argstr;
};

void help(void){
	printf("USAGE:\n");
}

void status(void){
	printf("STATUS:\n");
}

void alloc_options(void){
	struct options *p;
	if((p = malloc(sizeof(struct options) * 1)) == UNLL){
		printf("failed : malloc() in alloc_options().\n");
		exit(1);
	}
	if(((*p).argstr = malloc(sizeof(char) * LEN)) == NULL){
		printf("failed : malloc() in alloc_options().\n");
		exit(1);
	}
}

void init_options(struct options *opt){
}

int get_options(int optc, char **optv, struct options *opt){
	int i = 0;
	for(i=0;i<optc;i++){
	}
}

int main(int argc, char **argv){
	return(0);
}
