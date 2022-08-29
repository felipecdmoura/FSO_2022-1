#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

/*  SIGUSR1 - câmera do Igor3k
    SIGUSR2 - câmera do Monark
    SIGINT - câmera do Convidado 1
    SIGTERM - câmera do Convidado 2
    SIGALRM - câmera geral void trata(int sig)*/

void trataSinal(int sig)
{
    int eof;
    char str[11];

    eof = scanf("%s", str);

    if (eof == EOF)
    {
        exit(0);
    }

    if (sig == SIGUSR1 && (strcmp(str, "Igor3k") == 0))
    {
        printf("Certo\n");
    }
    else if (sig == SIGUSR2 && (strcmp(str, "Monark") == 0))
    {
        printf("Certo\n");
    }
    else if (sig == SIGINT && (strcmp(str, "Con1") == 0))
    {
        printf("Certo\n");
    }
    else if (sig == SIGTERM && (strcmp(str, "Con2") == 0))
    {
        printf("Certo\n");
    }
    else if (sig == SIGALRM && (strcmp(str, "Silencio") == 0))
    {
        printf("Certo\n");
    }
    else
    {
        printf(" Erro\n");
        kill(getppid(), SIGALRM);
    }
}
int main()
{

    signal(SIGUSR1, trataSinal);
    signal(SIGUSR2, trataSinal);
    signal(SIGINT, trataSinal);
    signal(SIGTERM, trataSinal);
    signal(SIGALRM, trataSinal);

    while (1)
        pause();

    return 0;
}