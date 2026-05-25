#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define N 64
#define L 8
// Графы  G=(V,E) , [v]-мощность множества вершин, [E]-nj;t тоже самое но для ребер.
// Связный граф- это когда мы из любой вершины можем попасть в любую другую.
// Взвешенный граф - это в котором каждому ребро мы сопостовляем число оно будет называться  его весом.
// Неориентированный граф — это граф, в котором все связи (рёбра) работают в обе стороны.
// Задаеться двумерным массивом.
// Алгоритм поиска в ширину .
// start , and ] dist[N]  dist [i] 
// Заполнить массив dist  “-1” ；dist start[0] ; диаппазон a and b = 0; quent [b]= start ; b++
// 2) while (a < b)
// int curent = qurent [a] / a++
// 


void J_neibor(int J[N][N]){

    int x[N], y[N], x_c =0 , y_c =0;
    for (int i =0; i<N ; i++ ){
x[i] = x_c;
y[i] = y_c;
x_c++;
if (x_c == L){

    x_c =0;
    y_c++;
}

    }

    for (int i = 0 ; i < N ; i++){
for (int j =0; j < N; j++ ){

    int delta_x = x[i]-x[j];
    int delta_y = y[i]- y[j];
    int r2 = delta_x * delta_x + delta_y * delta_y;
    if (r2 == 1){

        J[i][j] =  1;
    }
}

    }
}

void J_print(int J[N][N]){
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
printf ("%d", J[i][j]);

        }
        printf("\n");
    }
} 

void dist_start( int dist[N]){
    for(int i = 0; i < N; i++){
       dist [i] = -1;
    }

}



 int step_calc(int start, int end, int J[N][N]){
    int dist[N];
    dist_start(dist);
    dist[start] = 0;
    int a =0 , b = 0;
    int queue[N];
    queue[b++]= start;
    while (a < b){
         int current = queue[a++];
         for(int neibor = 0; neibor < N; neibor++){
            if (J[current][neibor]== 1 && dist[neibor]== -1){
                dist[neibor] = dist[current] + 1;
                if (neibor == end){
                    return dist[neibor];
                }
                queue[b++] = neibor;
            }
         }
    }
    return -1;
 }
int main(){
int J[N][N] ={{0}};
J_neibor(J);
// J_print(J);
// int stepen = 0 ;
// int k = 8;
// for (int i = 0; i < N ; i++){
//     stepen += J[k][i];

// }
// printf ("stepen = %d\n", stepen);
// int E = 0;
// for (int i = 0; i < N; i++){
//     for (int j = i + 1; j < N; j++){
//         E += J[i][j];
//     }
// }
// printf("%d\n", E);

int start = 0, end = 63;
int step = step_calc(start, end, J);
printf ("step =%d\n",step);
    return 0 ;
}