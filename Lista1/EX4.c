#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int count = 0;
pid_t f;

void temp(int sig)
{
    printf("temp\n");
    return;
}

void trataSinal(int sig)
{
}

int main()
{

    signal(SIGUSR1, trataSinal);
    signal(SIGUSR2, trataSinal);

    pause();
    f = fork();
    if (f > 0)
    {
        pause();
        wait(NULL);
        pause();
        exit(0);
    }
    else if (f == 0)
    {
        exit(0);
    }

    return 0;
}