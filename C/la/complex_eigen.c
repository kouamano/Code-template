#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include "../../../include/alloc.c"
#include "../../../include/data_read.c"
#define LEN 1024

struct options {
	int help;
	int stat;
	int check;
	int nlines;
	int ntuples;
	char *file;
};

void help(void){
	printf("USAGE:\n");
	printf(" template [-h] [-s] [-c] nlines=<nlines> ntuples=<ntuples> if=<file>.\n");
	printf("  -h : help.\n");
	printf("  -s : stat.\n");
	printf("  -c : check args.\n");
	printf("  file : set *chars (len < 1024).\n");
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
	if(((*p).file = malloc(sizeof(char) * LEN)) == NULL){
		printf("failed : malloc() in alloc_options().\n");
		exit(1);
	}
	return(p);
}

void init_options(struct options *opt){
	(*opt).help = 0;
	(*opt).stat = 0;
	(*opt).check = 0;
	(*opt).nlines = 0;
	(*opt).ntuples = 0;
	(*opt).file[0] = '\0';
}

void get_options(int optc, char **optv, struct options *opt){
	int i = 0;
	for(i=0;i<optc;i++){
		if(strcmp(optv[i],"-h") == 0){
			(*opt).help = 1;
		}else if(strcmp(optv[i],"-s") == 0){
			(*opt).stat = 1;
		}else if(strcmp(optv[i],"-c") == 0){
			(*opt).check = 1;
		}else if(strncmp(optv[i],"nlines=",7) == 0){
			sscanf(optv[i],"nlines=%d",&(*opt).nlines);
		}else if(strncmp(optv[i],"ntuples=",7) == 0){
			sscanf(optv[i],"ntuples=%d",&(*opt).ntuples);
		}else if(strncmp(optv[i],"if=",3) == 0){
			sscanf(optv[i],"if=%s",(*opt).file);
		}else{
			fprintf(stderr,"Unknown: %s\n",optv[i]);
			exit(0);
		}
	}
}

void check_options(struct options *opt){
	printf("OPTIONS:\n");
	printf(" opt.nlines:%d:\n",(*opt).nlines);
	printf(" opt.ntuples:%d:\n",(*opt).ntuples);
	printf(" opt.if:%s:\n",(*opt).file);
}

int main(int argc, char **argv){
	struct options *opt;
	int ie = 0;
	FILE *FP;
	double re,im;
	complex **xtable;
	int i,j;
	opt = alloc_options();
	init_options(opt);
	get_options(argc-1, argv+1, opt);
	if(argc == 1){
		(*opt).help = 1;
	}
	if((*opt).help == 1){
		help();
		ie = 1;
	}
	if((*opt).stat == 1){
		status();
		ie = 1;
	}
	if((*opt).check == 1){
		check_options(opt);
		ie = 1;
	}
	if(strlen((*opt).file) == 0){
		ie = 1;
	}
	if(ie == 1){
		exit(0);
	}

	/* main routine */
	char jobvl = 'N';
	char jobvr = 'V';
	int size;
	// complex A; // = xtable
	int lda;
	  lda = (*opt).nlines;
	complex *wr;
	  wr = x_alloc_vec((*opt).nlines);
	complex vlDUMMY[1];
	int ldvlDUMMY = 1;
	complex *vr;
	  vr = x_alloc_vec((*opt).nlines * (*opt).nlines);
	int ldvr;
	  ldvr = (*opt).nlines;
	complex *work;
	  work = x_alloc_vec(2 * (*opt).nlines);
	int lwork;
	  lwork = 2 * (*opt).nlines;
	double *rwork;
	  rwork = d_alloc_vec(2 * (*opt).nlines);
	int info;
	xtable = x_alloc_mat((*opt).nlines,(*opt).ntuples);
	FP = fopen((*opt).file,"r");
	read_xtable_from_stream((*opt).nlines,(*opt).ntuples,FP,xtable);
	fclose(FP);
	
	/* print out */
	for(i=0;i<(*opt).nlines;i++){
		for(j=0;j<(*opt).ntuples;j++){
			printf(" %lf+%lfI",creal(xtable[i][j]),cimag(xtable[i][j]));
		}
		printf("\n");
	}
	return(0);
}
