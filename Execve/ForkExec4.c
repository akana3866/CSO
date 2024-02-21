#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h> 


int main(int argc, char **argv)
{
  // populate arraay with random numbers
  int child_status;
  pid_t pid;
  int i;
    pid = fork();
   char *array[3];
   array[0]="Hello";
   array[1] ="There";
   array[2]="Test";
   if (pid == 0) {
    pid= execve("Process4", array, NULL);
     }
   int num;
 printf("What is 2 + 2" );
  while (num != 4) {
   scanf("%d", &num); 
   if (num==4) {
           printf("You win                    \n" );    
          }  else {
                   printf("%i incorrect - try again ",num);   
                   printf("\r\b\r");
              }
      
   }
   return(0);
   }

  
