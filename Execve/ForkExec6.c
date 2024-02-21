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
  int thispid;
  int i;
    pid = fork();
   char *array[3];
   array[0]="Process";
   array[1] ="Start";
   array[2]="Timer";
   if (pid == 0) {
    pid= execve("Process6", array, NULL);
     }
   int num;
 printf("What is 2 + 2" );
  while (num != 4) {
   scanf("%d", &num); 
   if (num==4) {
           printf("You win                    \n" );    
           kill(pid, SIGKILL);
      } else if (num==0) {
               printf("%i resetting time       ",num);
               printf("\r\b\r");     
               kill(pid, SIGINT);
          }  else {
                   printf("%i incorrect - try again ",num);   
                   printf("\r\b\r");
              }
      
   }
   return(0);
   }

  
