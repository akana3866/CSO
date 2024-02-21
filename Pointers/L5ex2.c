#include <stdio.h>
 
void FuncX(char* inarr[]) {
   inarr[0]="xyz";
    }

int main()
 {
    char* anames[3] = {"alice","bob","clark"};
    
    char** p_names =  anames;
    int i;
    
    for (i = 0; i < 3; i++ ) {
    printf ("%s \t %s \n", anames[i], p_names[i] );
    printf ("%p \t %p \n",  anames[i],  p_names[i] );
    }
    FuncX(anames);
  
    for (i = 0; i < 3; i++ ) {
    printf ("%s \t %s \n", anames[i], p_names[i] );
    printf ("%p \t %p \n",  anames[i],  p_names[i] );
    } 

 
 }

  
  
