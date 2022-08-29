#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

long N, *V1, *V2;

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void *sortV1(void *arg)
{
    qsort(V1, N, sizeof(long), cmp);
}

void *sortV2(void *arg)
{
    qsort(V2, N, sizeof(long), cmp);
}

int compareVet()
{
    int flag = 0;

    for (size_t i = 0; i < N; i++)
    {
        if (V1[i] != V2[i])
        {
            flag = 1;
        }
    }

    return flag;
}

int main()
{
    int flag;
    pthread_t t1, t2;

    scanf("%li", &N);

    V1 = malloc(sizeof(long) * N);
    V2 = malloc(sizeof(long) * N);

    for (size_t i = 0; i < N; i++)
    {
        scanf("%li", &V1[i]);
    }

    for (size_t i = 0; i < N; i++)
    {
        scanf("%li", &V2[i]);
    }

    pthread_create(&t1, NULL, sortV1, NULL);
    pthread_create(&t2, NULL, sortV2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    /* for (size_t i = 0; i < N; i++)
    {
        printf("%li ", V1[i]);
    }

    printf("\n");

    for (size_t i = 0; i < N; i++)
    {
        printf("%li ", V2[i]);
    }
    printf("\n"); */

    flag = compareVet();

    if (flag == 0)
    {
        printf("Mesmos elementos\n");
    }

    if (flag == 1)
    {
        printf("Diferentes\n");
    }

    free(V1);
    free(V2);
    return 0;
}
