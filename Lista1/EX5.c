#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int matrix_1[2000][2000], matrix_2[2000][2000], result_1[1000][1000], result_2[1000][1000];

void trataSinal(int sig)
{
    return;
}

int main()
{

    signal(SIGUSR1, trataSinal);
    signal(SIGUSR2, trataSinal);
    signal(SIGALRM, trataSinal);
    int mat_dim, sum;

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
            printf("1 finalizou!\n");
            pause();
            printf("Todos finalizaram!\n");
            sleep(2);
            kill(son_1, SIGUSR2);
            pause();
            printf("%d Printou\n", son_1);
            kill(son_2, SIGTERM);
            pause();
            printf("%d Printou\n", son_2);
            sleep(5);
            wait(NULL);
            exit(0);
        }
        else if (son_2 == 0)
        {
            signal(SIGUSR2, trataSinal);

            for (size_t i = 0; i < (mat_dim / 2); i++)
            {
                for (size_t j = 0; j < mat_dim; j++)
                {
                    sum = 0;
                    for (size_t k = 0; k < mat_dim; k++)
                    {
                        sum += matrix_1[i][k] * matrix_2[k][j];
                    }

                    result_1[i][j] = sum;
                    // printf("%d ", result_1[i][j]);
                }
            }

            sleep(2);
            kill(getppid(), SIGUSR1);
            pause();
            for (size_t i = 0; i < (mat_dim / 2); i++)
            {
                for (size_t j = 0; j < mat_dim; j++)
                {
                    printf("%d ", result_1[i][j]);
                }

                printf("\n");
            }
            sleep(2);
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
                sum = 0;
                for (size_t k = 0; k < mat_dim; k++)
                {
                    sum += matrix_1[i][k] * matrix_2[k][j];
                }

                result_2[i - (mat_dim / 2)][j] = sum;
                // printf("%d ", result_2[(i * 2) - mat_dim][j]);
            }
        }
        sleep(4);
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
        sleep(2);
        kill(getppid(), SIGALRM);
        exit(0);
    }

    return 0;
}