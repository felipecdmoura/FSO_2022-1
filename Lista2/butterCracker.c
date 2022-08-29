#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

long Mi, Mf, part, count;
unsigned int gen[100000], rand_num1[20], rand_num2[20], rand_num3[20], rand_num4[20], rand_num5[20], rand_num6[20], rand_num7[20], rand_num8[20];
int finish_flag;

pthread_t t1, t2, t3, t4, t5, t6, t7, t8;
sem_t s1;

void *findSeedBig_1(void *arg)
{
    unsigned int seed_1;
    int flag;

    for (long i = Mi; i < Mi + part; i++)
    {
        if (finish_flag == 1)
        {
            break;
        }

        flag = 0;
        seed_1 = i;
        for (size_t k = 0; k < count; k++)
        {
            for (int j = 1; j < 10000; j++)
                rand_r(&seed_1);

            rand_num1[k] = rand_r(&seed_1) % 256;

            if (rand_num1[k] != gen[k])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            finish_flag = 1;
            printf("%li\n", i);
            break;
        }
    }
}

void *findSeedBig_2(void *arg)
{
    unsigned int seed_2;
    int flag;

    for (long i = Mi + part; i < Mi + (part * 2); i++)
    {
        if (finish_flag == 1)
        {
            break;
        }

        flag = 0;
        seed_2 = i;
        for (size_t k = 0; k < count; k++)
        {
            for (int j = 1; j < 10000; j++)
                rand_r(&seed_2);

            rand_num2[k] = rand_r(&seed_2) % 256;

            if (rand_num2[k] != gen[k])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            finish_flag = 1;
            printf("%li\n", i);
            break;
        }
    }
}

void *findSeedBig_3(void *arg)
{
    unsigned int seed_3;
    int flag;

    for (long i = Mi + (part * 2); i < Mi + (part * 3); i++)
    {
        if (finish_flag == 1)
        {
            break;
        }

        flag = 0;
        seed_3 = i;
        for (size_t k = 0; k < count; k++)
        {
            for (int j = 1; j < 10000; j++)
                rand_r(&seed_3);

            rand_num3[k] = rand_r(&seed_3) % 256;

            if (rand_num3[k] != gen[k])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            finish_flag = 1;
            printf("%li\n", i);
            break;
        }
    }
}

void *findSeedBig_4(void *arg)
{
    unsigned int seed_4;
    int flag;

    for (long i = Mi + (part * 3); i < Mi + (part * 4); i++)
    {
        if (finish_flag == 1)
        {
            break;
        }

        flag = 0;
        seed_4 = i;
        for (size_t k = 0; k < count; k++)
        {
            for (int j = 1; j < 10000; j++)
                rand_r(&seed_4);

            rand_num4[k] = rand_r(&seed_4) % 256;

            if (rand_num4[k] != gen[k])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            finish_flag = 1;
            printf("%li\n", i);
            break;
        }
    }
}

void *findSeedBig_5(void *arg)
{
    unsigned int seed_5;
    int flag;

    for (long i = Mi + (part * 4); i < Mi + (part * 5); i++)
    {
        if (finish_flag == 1)
        {
            break;
        }

        flag = 0;
        seed_5 = i;
        for (size_t k = 0; k < count; k++)
        {
            for (int j = 1; j < 10000; j++)
                rand_r(&seed_5);

            rand_num5[k] = rand_r(&seed_5) % 256;

            if (rand_num5[k] != gen[k])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            finish_flag = 1;
            printf("%li\n", i);
            break;
        }
    }
}

void *findSeedBig_6(void *arg)
{
    unsigned int seed_6;
    int flag;

    for (long i = Mi + (part * 5); i < Mi + (part * 6); i++)
    {
        if (finish_flag == 1)
        {
            break;
        }

        flag = 0;
        seed_6 = i;
        for (size_t k = 0; k < count; k++)
        {
            for (int j = 1; j < 10000; j++)
                rand_r(&seed_6);

            rand_num6[k] = rand_r(&seed_6) % 256;

            if (rand_num6[k] != gen[k])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            finish_flag = 1;
            printf("%li\n", i);
            break;
        }
    }
}

void *findSeedBig_7(void *arg)
{
    unsigned int seed_7;
    int flag;

    for (long i = Mi + (part * 6); i < Mi + (part * 7); i++)
    {
        if (finish_flag == 1)
        {
            break;
        }

        flag = 0;
        seed_7 = i;
        for (size_t k = 0; k < count; k++)
        {
            for (int j = 1; j < 10000; j++)
                rand_r(&seed_7);

            rand_num7[k] = rand_r(&seed_7) % 256;

            if (rand_num7[k] != gen[k])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            finish_flag = 1;
            printf("%li\n", i);
            break;
        }
    }
}

void *findSeedBig_8(void *arg)
{
    unsigned int seed_8;
    int flag;

    for (long i = Mi + (part * 7); i <= Mf; i++)
    {
        if (finish_flag == 1)
        {
            break;
        }

        flag = 0;
        seed_8 = i;
        for (size_t k = 0; k < count; k++)
        {
            for (int j = 1; j < 10000; j++)
                rand_r(&seed_8);

            rand_num8[k] = rand_r(&seed_8) % 256;

            if (rand_num8[k] != gen[k])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            finish_flag = 1;
            printf("%li\n", i);
            break;
        }
    }
}

void *findSeed_1(void *arg)
{
    unsigned int seed_1;
    int flag;

    for (long i = Mi; i < part; i++)
    {

        flag = 0;
        seed_1 = i;
        for (size_t k = 0; k < count; k++)
        {
            for (int j = 1; j < 10000; j++)
                rand_r(&seed_1);

            rand_num1[k] = rand_r(&seed_1) % 256;

            if (rand_num1[k] != gen[k])
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("%li\n", i);
            break;
        }
    }
}

void *findSeed_2(void *arg)
{
    unsigned int seed_2;
    int flag;

    for (long i = part; i <= Mf; i++)
    {
        flag = 0;
        seed_2 = i;
        for (size_t k = 0; k < count; k++)
        {
            for (int j = 1; j < 10000; j++)
                rand_r(&seed_2);

            rand_num2[k] = rand_r(&seed_2) % 256;

            if (rand_num2[k] != gen[k])
            {

                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("%li\n", i);
            break;
        }
    }
}

int main()
{
    finish_flag = 0;
    count = 0;
    scanf("%li %li", &Mi, &Mf);

    // printf("mid: %li\n", mid);

    while (scanf("%u", &gen[count]) != EOF)
    {
        count++;
    }

    if (count > 10)
    {
        count = 10;
    }

    if (Mf - Mi == 0)
    {
        printf("%li\n", Mi);
    }
    else if (Mf - Mi < 100)
    {
        part = (Mf + Mi) / 2;

        pthread_create(&t1, NULL, findSeed_1, NULL);
        pthread_create(&t2, NULL, findSeed_2, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
    }
    else
    {
        part = (Mf - Mi) / 8;

        // printf("%li\n", part);
        pthread_create(&t1, NULL, findSeedBig_1, NULL);
        pthread_create(&t2, NULL, findSeedBig_2, NULL);
        pthread_create(&t3, NULL, findSeedBig_3, NULL);
        pthread_create(&t4, NULL, findSeedBig_4, NULL);
        pthread_create(&t5, NULL, findSeedBig_5, NULL);
        pthread_create(&t6, NULL, findSeedBig_6, NULL);
        pthread_create(&t7, NULL, findSeedBig_7, NULL);
        pthread_create(&t8, NULL, findSeedBig_8, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        pthread_join(t3, NULL);
        pthread_join(t4, NULL);
        pthread_join(t5, NULL);
        pthread_join(t6, NULL);
        pthread_join(t7, NULL);
        pthread_join(t8, NULL);
    }

    return 0;
}
