#include<stdio.h>
//Реализуйте алгоритм, который находит все числа в диапазоне от 1 до m, сумма цифр которых равняется n. 
// Реализовать при помощи рекурсивной функции.


int sum(int num) {
    if (num < 10) {
        return num;
    } 
    else {
        return (num % 10) + sum(num / 10);
    }
}

void find_num(int num, int m, int n){
    if (num > m) {
        printf("\n");
        printf("вышли за значение m = %d", m);
        return;
    } 
    int k = sum(num);
    if (k == n) {
        printf("%d ", num);
    }
    find_num(num + 1, m, n);
}

int main() {
    int m = 100;
    int n = 6;
    find_num(1, m, n);
    return 0;
}
