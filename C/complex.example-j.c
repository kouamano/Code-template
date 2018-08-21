#include <stdio.h>
#include <complex.h>
#undef I
#define j _Imaginary_I

      complex double twidder[64][64];
      int flag = 0;
      int i, k;

      FILE *twidderFile;

      twidderFile = fopen("twidder_factor.txt", "r");

      if(twidderFile == NULL)
      {
          fprintf(stderr, "Can't open the file twidder_factor.txt!\n");
          exit(1);
      }

      for(i = 0; i < 64; i++)
      {
          for(k = 0; k < 64; k++)
          {
              if((flag = fscanf(twidderFile, "%f %f", &twidder[i][k])) == EOF)
              {
                  break;
              }
          }
          if(flag == EOF)
          {
              break;
          }
      }

      if(flag == EOF)
      {
          fprintf(stderr, "Error has been encountered while reading values from twidder_factor.txt!\n");
          exit(1);
      }

for(i = 0; i < 64; i++)
{
   for(k = 0; k < 64; k++)
   {
      printf("%.0f %c %.0fj\t", creal(twidder[i][k]), cimag(twidder[i][k]) >= 0 ? '+' : '-', cimag(twidder[i][k]) >= 0 ? cimag(twidder[i][k]) : -cimag(twidder[i][k]));
   }
   printf("\n");
}

