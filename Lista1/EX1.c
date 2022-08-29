#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int ver = 0;

void trata(int sig)
{

    if (sig == SIGTERM)
    {
        printf("Recebi %d\n", SIGTERM);

        if (ver == 2)
        {
            printf("Senha acionada\n");
            ver = 3;
        }
        else
        {
            ver = 0;
        }
    }
    else if (sig == SIGUSR1)
    {
        printf("Recebi %d\n", SIGUSR1);

        if (ver == 3)
        {
            printf("Tchau\n");
            exit(0);
        }
        else
        {
            ver = 0;
        }
    }
    else if (sig == SIGUSR2)
    {
        printf("Recebi %d\n", SIGUSR2);

        if (ver == 1)
        {
            ver = 2;
        }
        else
        {
            ver = 0;
        }
    }
    else if (sig == SIGINT)
    {
        printf("Recebi %d\n", SIGINT);

        ver = 1;
    }
    // printf("[%d]\n", ver);
}

int main()
{

    signal(SIGTERM, trata);
    signal(SIGUSR1, trata);
    signal(SIGUSR2, trata);
    signal(SIGINT, trata);
    while (1)
        pause();

    return 0;
}