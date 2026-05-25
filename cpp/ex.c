#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

struct range{
double min, max;
    
};

struct integral
{
    double value, sigma;
};

double f(double x ){

return x * x;

};

 struct range range_calc(double a , double b, double step){
    struct range Range;
    Range.min = f(a);
    Range.max = f(a);
    for(double x_i =a +step; x_i <= b; x_i+=step){
        if (f(x_i)> Range.max){
            Range.max =f(x_i);
        }
        if(f(x_i)< Range.min){
            Range.min = f(x_i);
        }
    }
    if (Range.min > 0){
        Range.min =0;
    }
    if(Range.max < 0){
        Range.max =0;
    }
    return Range;
 }
 double sigma_calc(int m , int k, int n , double S_rectangle){
    double D = (double)k /n -(((double )m/ n ) * ((double)m /n));
    D  /= n;
    double sigma = S_rectangle * sqrt(D);
    return sigma;
 }

 struct integral integral_mc_calc(double a, double b, struct range Range , int n ){
int m = 0 , k = 0;
for (int i = 0; i <n; i++){
    double x =a + (double)rand() / RAND_MAX * (b -a );
    double y = Range.min + (double)rand() / RAND_MAX * (Range.max -Range.min);
    if(y <= f(x)&& y >0){
        m++;
        k++;
    }
    if (y >= f(x) && y< 0){
        m--;
        k++;
    }
}
 double S_rectangle = (b -a) *(Range.max -Range.min);
 struct integral Integral;
 Integral.value = m * S_rectangle /n ; 
 Integral.sigma = sigma_calc(m , k , n, S_rectangle);
 return Integral;
 }


int main(){
double a = 0.0, b= 2.0;
double step = 0.0001;
struct range Range = range_calc( a, b, step);

printf ("%lf %lf", Range.min , Range.max);
srand(time(NULL));
int n = 100000;
struct  integral Integral =integral_mc_calc( a, b , Range, n);
printf("resuit = %lf +- %lf", Integral.value, 3 * Integral.sigma);

    return 0;
}