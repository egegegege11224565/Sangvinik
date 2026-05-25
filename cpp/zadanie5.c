#include <stdio.h>

int rec(int n, int m, int a);    

int main()
{
    int n = 5;
    int m = 1000;
    int a = 1;
    rec(n, m, a);
    return 0;
}

int rec(int n, int m, int a)
{   
    if(a > m)
    {
        return 0;
    }

    int sum = 0;
    int b = a;
    while(b > 0) {
        sum += (b % 10);
        b /= 10; 
    } 

    if(sum == n)
    {
        printf("%d ",a);
    }
    return rec(n, m, a + 1);
} 