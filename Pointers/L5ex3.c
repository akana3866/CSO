#include <stdio.h>
 
void FuncX(char** parr[]) {
int j;

for (j = 0; j < 3; j++ ) {
      *parr[j] ="xyz";
   }
 }

int main()
 {
    char* anames[3] = {"alice","bob","clark"};
    char* bnames[3] = {"david","ellen","frank"};
    char* cnames[3] = {"george","hong","isheil"};
    
    char** p_names[3];
    p_names[0] =  anames;
    p_names[1] =  bnames;
    p_names[2] =  cnames;
    int i;
      
    printf ("%s \t %s \t \%s \n", anames[0],  anames[1],   anames[2] );
    printf ("%s \t %s \t \%s \n", bnames[0],  bnames[1],   bnames[2] );
    printf ("%s \t %s \t \%s \n", cnames[0],  cnames[1],   cnames[2] );
     

    FuncX(p_names);
  
    printf ("%s \t %s \t \%s \n", anames[0],  anames[1],   anames[2] );
    printf ("%s \t %s \t \%s \n", bnames[0],  bnames[1],   bnames[2] );
    printf ("%s \t %s \t \%s \n", cnames[0],  cnames[1],   cnames[2] );
     
     
    } 

 
 

  
  
