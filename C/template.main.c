#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1024

struct options {
	int help;
	int stat;
	int check;
	int argint;
	char *argstr;
};

void help(void){
	printf("USAGE:\n");
	printf(" template [-h] [-s] [-c].\n");
	printf("  -h : help.\n");
	printf("  -s : stat.\n");
	printf("  -c : check args.\n");
}

void status(void){
	printf("STATUS:\n");
	printf(" this program is template.\n");
}

struct options *alloc_options(void){
	struct options *p;
	if((p = malloc(sizeof(struct options) * 1)) == NULL){
		printf("failed : malloc() in alloc_options().\n");
		exit(1);
	}
	if(((*p).argstr = malloc(sizeof(char) * LEN)) == NULL){
		printf("failed : malloc() in alloc_options().\n");
		exit(1);
	}
	return(p);
}

void init_options(struct options *opt){
	(*opt).help = 0;
	(*opt).stat = 0;
	(*opt).check = 0;
	(*opt).argint = 0;
	(*opt).argstr[0] = '\0';
}

void get_options(int optc, char **optv, struct options *opt){
	int i = 0;
	for(i=0;i<optc;i++){
		if(strcmp(optv[i],"-h") == 0){
			(*opt).help = 1;
		}else if(strcmp(optv[i],"-s") == 0){
			(*opt).stat = 1;
		}else if(strncmp(optv[i],"str=",4) == 0){
			sscanf(optv[i],"str=%s",(*opt).argstr);
		}
	}
}

void check_options(struct options *opt){
	printf("opt.help:%d:",(*opt).help);
	printf("opt.argstr:%s:",(*opt).argstr);
}

int main(int argc, char **argv){
	struct options *opt;
	opt = alloc_options();
	init_options(opt);
	get_options(argc-1, argv+1, opt);
	return(0);
}
