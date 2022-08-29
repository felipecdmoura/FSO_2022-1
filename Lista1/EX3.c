#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int count = 0;
void trataSinal(int sig)
{

    if (sig == SIGUSR1)
    {
        printf("SIGUSR1 eh para aproveitar mais um pouco\n");
    }
    else if (sig == SIGALRM)
    {
        count++;

        if (count == 3)
        {
            printf("Os incomodados que se mudem, tchau\n");
            exit(0);
        }
        else
        {
            printf("Ai que sono, quero dormir mais um pouco\n");
        }
    }
}
int main()
{

    signal(SIGUSR1, trataSinal);
    signal(SIGALRM, trataSinal);

    while (1)
        pause();

    return 0;
}