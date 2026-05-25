#include <stdio.h>
// Напишите программу, которая определяет, является ли массив целых чисел подмассивом другого массива.
// Для определения объявите отдельную функцию, внутри функции для доступа к элементам массива использовать операцию разыменовывания.
int func(int mass[], int podmass[], int n, int m);

int main()
{
    int mass[] = {10, 20, 30, 40, 50};
    int podmass[] = {40, 50, 60};
    int n = sizeof(mass) / sizeof(mass[0]);
    int m = sizeof(podmass) / sizeof(podmass[0]);
    printf("n = %d, m = %d, sizeof(mass) = %d, sizeof(mass[0]) = %d\n",n , m, sizeof(mass), sizeof(mass[0]));
    func(mass, podmass, n, m);
    return 0;
}

int func(int mass[], int podmass[], int n, int m){
    int *ptr;
    for (ptr = &mass[0]; ptr <= &mass[n]; ptr++) {
        int count = 0;
        
        for (int j = 0; j < m; j++) {
            if (*(ptr + j) == *(podmass + j)) {  
                count++;
            }else {
                break;
            } 
        }

        if (count == m) {
            printf("podmass naiden, index: %d\n", ptr - &mass[0]);
            return 0;
        }
    }
    printf("podmass ne naiden\n");
    return 0;
}