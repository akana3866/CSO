#include <unistd.h> 
#include <sys/types.h> 
#include <errno.h> 
#include <stdio.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include<time.h> 
pid_t pid;
void handle_sigint(int sig) 
{ 
  kill(pid, SIGKILL);
  printf("\ncan not reset time again - game over\n" );
  exit(0);
                
} 
int main(int argc, char **argv)
{
  // populate arraay with random numbers
  signal(SIGINT, handle_sigint);
  int child_status;
  
  int thispid;
  int i;
    pid = fork();
   if (pid == 0) {
    pid= execve("Process6P1",NULL, NULL);
     }
   int num;
 printf("What is 2 + 2" );
  while (num != 4) {
   scanf("%d", &num); 
   if (num==4) {
           printf("You win                    \n" );    
           kill(pid, SIGKILL);
      } else if (num==0) {
               kill(pid, SIGINT);
               printf("%i resetting time       ",num);     
               printf("\r\b\r");  
  } else if (num==-1) {
                kill(pid, SIGKILL);
               printf("%i game over               \n",num);          
               break;
          }  else {
                   printf("%i incorrect - try again ",num);   
                   printf("\r\b\r");
              }
      
   }
   return(0);
   }

  
