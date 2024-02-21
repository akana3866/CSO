/* This code was assignment was completed fully by Aditi Kanaujia.
How the code works is it generates a random question and creates
and signal handle that waits for a signal from the child
once it gets a signal from the child it calls the handle_timeout
which indicates that the time is up and to move on to the next question
while counting its a miss. Otherwise the player answers the question
and if correct counts it as correct else if incorrect counts it as incorrect and 
gives you another try */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#define MAX_QUESTIONS 10

pid_t pid;
int correctAnswers = 0;
int incorrectAnswers = 0;
int missedQuestions = 0;
int currentAnswer;
volatile sig_atomic_t timeIsUp = 0;

void handle_timeout(int sig) {
    if (!timeIsUp) {
        missedQuestions++;
        printf("\nTime's up! Type any number to move on\n");
        timeIsUp = 1;  // Indicate that time is up
    }
    kill(pid, SIGKILL);  // Kill the timer
}

void generate_question(int *a, int *b, char *op) {
    *a = rand() % 100;  // Random number between 0 and 99
    *b = rand() % 100;  // Random number between 0 and 99
    int op_index = rand() % 3;
    char operators[] = {'+', '-', '*'};
    *op = operators[op_index];
    switch (op_index) {
        case 0:
            currentAnswer = *a + *b;
            break;
        case 1:
            currentAnswer = *a - *b;
            break;
        case 2:
            currentAnswer = *a * *b;
            break;
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));  // Seed for random number generation
    int numQuestions;

    printf("Enter number of questions: ");
    scanf("%d", &numQuestions);
    numQuestions = (numQuestions > MAX_QUESTIONS) ? MAX_QUESTIONS : numQuestions;

    signal(SIGALRM, handle_timeout);  // Set up the signal handler

    for (int i = 0; i < numQuestions; i++) {
        int a, b;
        char op;
        generate_question(&a, &b, &op);

        pid = fork();
        if (pid == 0) {
            sleep(10);  // Child waits for 10 seconds
            exit(0);
        } else {
            alarm(5);  // Parent sets an alarm for 5 seconds
            timeIsUp = 0;  // Reset the timeIsUp flag for each question

            printf("What is %d %c %d? ", a, op, b);

            int userAnswer;
            while (!timeIsUp) {

                if (scanf("%d", &userAnswer) > 0) {
                    if(timeIsUp){
                            break;
                        }
                    if (userAnswer == currentAnswer) {
                        correctAnswers++;
                        printf("Correct!\n");
                        break;
                    } else {
                        incorrectAnswers++;
                        printf("Incorrect. ");
                        if (!timeIsUp) {
                            printf("Try again: ");
                        }
                        if(timeIsUp){
                            break;
                        }
                    }
                } else {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) { }
                    printf("Invalid input. Try again: ");
                }
            }

            kill(pid, SIGKILL); // Kill the timer
            wait(NULL); // Wait for child to finish
            
        }
    }

    printf("\nQuiz Summary:\n");
    printf("Correct Answers: %d\n", correctAnswers);
    printf("Incorrect Answers: %d\n", incorrectAnswers);
    printf("Missed Questions: %d\n", missedQuestions);

    return 0;
}
