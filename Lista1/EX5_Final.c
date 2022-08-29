#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int matrix_1[2000][2000], matrix_2[2000][2000], result_1[1000][1000], result_2[1000][1000];

int ver_1 = 0, ver_2 = 0;

void trataSinal(int sig)
{

    /* if (sig == SIGTERM)
    {
        printf("SIGTERM succeded\n");
    }
    if (sig == SIGALRM)
    {
        printf("SIGALRM succeded\n");
    } */

    return;
}

void trataVer1(int sig)
{
    ver_1++;
}

void trataVer2(int sig)
{
    ver_2++;
}

int main()
{

    signal(SIGUSR1, trataVer1);
    signal(SIGUSR2, trataVer2);
    signal(SIGALRM, trataSinal);

    int mat_dim;
    scanf("%d", &mat_dim);

    for (size_t i = 0; i < mat_dim; i++)
    {
        for (size_t k = 0; k < mat_dim; k++)
        {
            scanf("%d", &matrix_1[i][k]);
        }
    }

    for (size_t i = 0; i < mat_dim; i++)
    {
        for (size_t k = 0; k < mat_dim; k++)
        {
            scanf("%d", &matrix_2[i][k]);
        }
    }

    pid_t son_1 = fork();

    if (son_1 > 0)
    {
        pid_t son_2 = fork();

        if (son_2 > 0)
        {
            pause();
            while (ver_1 == 0 || ver_2 == 0)
            {
                pause();
            }

            kill(son_2, SIGTERM);
            pause();
            kill(son_1, SIGTERM);
            wait(NULL);
            wait(NULL);
        }

        else if (son_2 == 0)
        {
            signal(SIGTERM, trataSinal);

            for (size_t i = 0; i < (mat_dim / 2); i++)
            {
                for (size_t j = 0; j < mat_dim; j++)
                {

                    for (size_t k = 0; k < mat_dim; k++)
                    {
                        result_1[i][j] += matrix_1[i][k] * matrix_2[k][j];
                    }
                }
            }

            kill(getppid(), SIGUSR2);
            pause();

            for (size_t i = 0; i < (mat_dim / 2); i++)
            {
                for (size_t j = 0; j < mat_dim; j++)
                {
                    printf("%d ", result_1[i][j]);
                }

                printf("\n");
            }

            kill(getppid(), SIGALRM);
            exit(0);
        }
    }
    else if (son_1 == 0)
    {
        signal(SIGTERM, trataSinal);

        for (size_t i = (mat_dim / 2); i < mat_dim; i++)
        {
            for (size_t j = 0; j < mat_dim; j++)
            {

                for (size_t k = 0; k < mat_dim; k++)
                {
                    result_2[i - (mat_dim / 2)][j] += matrix_1[i][k] * matrix_2[k][j];
                }
            }
        }
        kill(getppid(), SIGUSR1);
        pause();

        for (size_t i = 0; i < (mat_dim / 2); i++)
        {
            for (size_t j = 0; j < mat_dim; j++)
            {
                printf("%d ", result_2[i][j]);
            }
            printf("\n");
        }

        kill(getppid(), SIGALRM);
        exit(0);
    }

    return 0;
}