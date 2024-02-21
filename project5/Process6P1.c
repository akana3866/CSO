/*





*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int secs = 0;
int resets = 0;

void handle_sigint(int sig) {
    if (resets > 1) {
        pid_t ppid = getppid();
        kill(ppid, SIGUSR1); // Signal the parent that 5 seconds have passed
    } else {
        secs = 0; // Reset timer
    }
    resets++;
}

int main(int argc, char **argv) {
    sleep(1); // Initial delay
    signal(SIGINT, handle_sigint);

    while(secs < 10) {
        sleep(1);
        secs++;
        if (secs == 5) {
            pid_t ppid = getppid();
            kill(ppid, SIGUSR1); // Signal the parent that 5 seconds have passed
        }
    }

    // If 10 seconds pass, signal the parent that time is up
    pid_t ppid = getppid();
    kill(ppid, SIGUSR2);

    return 0;
}
