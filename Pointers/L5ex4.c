#include <stdio.h>
 
void FuncX(char** parr[], int num) {
int j;
int k;
char** tptr;
char* temp;
for (j = 0; j < num; j++ ) {
   tptr=parr[j];
   for (k=0; k<num/2; k++) {
     temp = *(tptr+k);
    *(tptr+k) = *(tptr+num -k-1);
    *(tptr+num -k-1)=  temp;
   }
 }
}

int main()
 {
    char* anames[4] = {"alice","bob","clark", "A4"};
    char* bnames[4] = {"david","ellen","frank","B4"};
    char* cnames[4] = {"george","hong","isheil","C4"};
    char* dnames[4] = {"D1","D2","D3","D4"};
    
    char** p_names[4];
    p_names[0] =  anames;
    p_names[1] =  bnames;
    p_names[2] =  cnames;
    p_names[3] =  dnames;
    int i;
      
    printf ("%s \t %s \t \%s \t \%s\n", anames[0],  anames[1],   anames[2], anames[3] );
    printf ("%s \t %s \t \%s \t \%s\n", bnames[0],  bnames[1],   bnames[2], bnames[3] );
    printf ("%s \t %s \t \%s \t \%s\n", cnames[0],  cnames[1],   cnames[2], cnames[3] );
    printf ("%s \t %s \t \%s \t \%s\n", dnames[0],  dnames[1],   dnames[2], dnames[3] );
     

    FuncX(p_names,4);
  
      printf ("%s \t %s \t \%s \t \%s\n", anames[0],  anames[1],   anames[2], anames[3] );
    printf ("%s \t %s \t \%s \t \%s\n", bnames[0],  bnames[1],   bnames[2], bnames[3] );
    printf ("%s \t %s \t \%s \t \%s\n", cnames[0],  cnames[1],   cnames[2], cnames[3] );
    printf ("%s \t %s \t \%s \t \%s\n", dnames[0],  dnames[1],   dnames[2], dnames[3] );
     
     
     
    } 

 
 

  
  
