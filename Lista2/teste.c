#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int main()
{

    int semente = 34872913;
    for (int i = 0; i < 77; i++)
    {
        for (int j = 1; j < 10000; j++)
            rand_r(&semente);
        printf("%d\n", rand_r(&semente) % 256);
    }
    return 0;
}
