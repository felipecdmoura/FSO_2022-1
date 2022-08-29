#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int matrix_1[2000][2000], matrix_2[2000][2000], result_1[1000][1000], result_2[1000][1000];

void trataSinal(int sig)
{
}

int main()
{
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

    for (size_t i = 0; i < (mat_dim / 2); i++)
    {
        for (size_t j = 0; j < mat_dim; j++)
        {
            printf("%d ", result_1[i][j]);
        }

        printf("\n");
    }

    for (size_t i = 0; i < (mat_dim / 2); i++)
    {
        for (size_t j = 0; j < mat_dim; j++)
        {
            printf("%d ", result_2[i][j]);
        }
        printf("\n");
    }

    /*  pid_t f = fork();

     if (f > 0)
     {
         f = fork();
         if (f == 0)
         {
         }

         sleep(20);
     }
     else if (f == 0)
     {
         for (size_t i = 0; i < (mat_dim / 2); i++)
         {
             for (size_t i = 0; i < mat_dim; i++)
             {
                 sum += matrix_1[i][]
             }
         }
     } */

    return 0;
}