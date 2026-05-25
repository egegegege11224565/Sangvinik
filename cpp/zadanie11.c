#include<stdio.h>
#include<stdlib.h>
// Программа должна реализовать матричное перемножение, записать результат в новый двумерный динамический массив и записать результат в новый файл.
int main()
{
    FILE *p = fopen("m1(z11).txt", "r");
    FILE *p1 = fopen("m2(z11).txt", "r");
    FILE *p2 = fopen("m3(z11).txt", "w");

    int rows = 3, cols = 3;
    int **mass = malloc(rows * sizeof(int*));
    int **mass1 = malloc(rows * sizeof(int*));
    int **mass2 = malloc(rows * sizeof(int*));

    for(int i = 0; i < cols; i++)
    {   
        mass[i]= malloc(cols * sizeof(int));
        mass1[i]= malloc(cols * sizeof(int));
        mass2[i]= malloc(cols * sizeof(int));
    }
    

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            fscanf(p, "%d", &mass[i][j]);
            fscanf(p1, "%d", &mass1[i][j]);
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {   
            mass2[i][j] = 0;
            for(int g = 0; g < rows; g++)
            {
                mass2[i][j] += mass[i][g] * mass1[g][j];
            }
            fprintf(p2, "%d ", mass2[i][j]); 
        }
        fprintf(p2, "\n"); 
    }

    for(int i = 0; i < rows; i++)
    {
        free(mass[i]);
        free(mass1[i]);
        free(mass2[i]);
    }

    free(mass);
    free(mass1);
    free(mass2);
    fclose(p);
    fclose(p1);
    fclose(p2);
    return 0;
}
