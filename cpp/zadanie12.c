#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
// Напишите программу, которая имитирует выпадение шаров в лотерее. 
#define N 6
int a[N];

void f();
void f1();
void sort();

int main()
{   
    srand(time(NULL));

    f();

    FILE *p = fopen("res12.txt", "w");

    for(int i = 0; i < N; i++)
    {
        fprintf(p, "%d ", a[i]);
    }

    fclose(p);

    return 0;
}

void f()
{
    for(int i = 0; i < 6; i++)
    {
        a[i] = 45;//1 + rand() % 45; 
        printf("%d ", a[i]);
    }
    printf("\n");
    f1();
}

void f1()
{
    
    for(int i = 0; i < 6; i++)
    {
        for(int j = i + 1 ; j < 6; j++)
        {
            if(a[i] == a[j])
            {
                printf("nashlo sovpadenie\n");
                a[j] = 1 + rand() % 45;
                
            }
        }    
    }
    printf("sovpadenii net\n");
    sort();
}

void sort()
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                int b = a[j];
                a[j] = a[j+1];
                a[j + 1] = b;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}