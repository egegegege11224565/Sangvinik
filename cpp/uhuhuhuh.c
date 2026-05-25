 #include<stdio.h>//Динамический массив.
 #include<stdlib.h>


//  int main(){
// int n = 1;
// int *p = malloc(n * sizeof(int));
// for (int i =0 ; i < n; i++){
// p[1] = i * i ;

// }
// for (int i =0; i < n; i++){

//     printf("%d", p[1]);
// }

// free(p);
//     return 0;
//  }

// int main(){
// int n;
// printf("VVEDITE CIFRU\n");
// scanf("%d", &n);
// int *p =malloc(n * sizeof(int));
// printf("VVEDITE KOLIHECTVJ ALIMENTOV\n");
// for(int i= 0; i < n; i++){
//     scanf("%d", &p[i]);

// }
// int k =0;
// for(int i =0; i <n; i++){
// if(p[i] % 2 ==0);{
//     k++;
// }
    
// }
// int *p2 = malloc(k * sizeof(int));
// if(k==0)


//     return 0;
// }
// int main(){

// int n = 5;// malloc(n * sizeof (int))//size_t
// int *p = calloc(n, sizeof(int));
// for(int i =0 ; i < n; i++){
//     printf("%d",p[i]);
// }
// free(p);
    // return 0;
// }

// int main(){
// int n = 5;
// int *p = malloc(n * sizeof(int));
// for(int i =0; i < n ; i++){

//     p[i] = i * i ;
// }
// int *t = realloc(p, n+1);






//     return 0;
// }

// int main(){

// int n = 5;
// int *p = malloc(n * sizeof(int));
// p[0] =12;
// p[1] =123;
// p[2] =1234;
// p[3] =12345;
// p[4] =123456;

// int max = p[0];
// for(int i =1; i < n; i++){

//     if(p[i]> max ){
//         max =p[i];
//     }
// }

// int *t = realloc(p,( n+1) * sizeof(int));
// if(t==NULL){
// return 0;

// }

// p=t;
// for(int i = n ; i >0 ; i--){
// p[i]= p[i -1];

// }


// p[0]= max;
// for(int i =0; i < n +1; i++){
//     printf("%d",p[i] );
// }
//     free(p);
//     return 0;
// }



// Функция для подсчета количества строк и столбцов в файле
void getMatrixSize(FILE *file, int *rows, int *cols) {
    char line[256];
    *rows = 0;
    *cols = 0;
    
    rewind(file);
    
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n') continue;
        
        (*rows)++;
        
        int temp_cols = 0;
        char *ptr = line;
        int num;
        
        while (sscanf(ptr, "%d", &num) == 1) {
            temp_cols++;
            while (*ptr && (*ptr == ' ' || *ptr == '\t')) ptr++;
            while (*ptr && *ptr != ' ' && *ptr != '\t' && *ptr != '\n') ptr++;
            while (*ptr && (*ptr == ' ' || *ptr == '\t')) ptr++;
        }
        
        if (temp_cols > *cols) {
            *cols = temp_cols;
        }
    }
}

// Функция для чтения матрицы из файла
int** readMatrixFromFile(const char *filename, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    
    getMatrixSize(file, rows, cols);
    
    // Выделяем память для матрицы
    int **matrix = (int**)malloc(*rows * sizeof(int*));
    for (int i = 0; i < *rows; i++) {
        matrix[i] = (int*)malloc(*cols * sizeof(int));
        for (int j = 0; j < *cols; j++) {
            matrix[i][j] = 0;
        }
    }
    
    // Читаем матрицу из файла
    rewind(file);
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    
    fclose(file);
    return matrix;
}

// Функция для вывода матрицы на экран
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция для умножения матриц
int** multiplyMatrices(int **matrix1, int rows1, int cols1, 
                       int **matrix2, int rows2, int cols2, 
                       int *resultRows, int *resultCols) {
    
    *resultRows = rows1;
    *resultCols = cols2;
    
    // Выделяем память для результирующей матрицы
    int **result = (int**)malloc(*resultRows * sizeof(int*));
    for (int i = 0; i < *resultRows; i++) {
        result[i] = (int*)malloc(*resultCols * sizeof(int));
        for (int j = 0; j < *resultCols; j++) {
            result[i][j] = 0;
        }
    }
    
    // Умножение матриц
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    return result;
}

// Функция для записи матрицы в файл
void writeMatrixToFile(int **matrix, int rows, int cols, const char *filename) {
    FILE *file = fopen(filename, "w");
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1) {
                fprintf(file, " ");
            }
        }
        if (i < rows - 1) {
            fprintf(file, "\n");
        }
    }
    
    fclose(file);
}

// Функция для освобождения памяти
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    const char *file1 = "matrix1.txt";
    const char *file2 = "matrix2.txt";
    const char *resultFile = "result.txt";
    
    int rows1, cols1, rows2, cols2;
    int **matrix1, **matrix2, **result;
    
    // Чтение первой матрицы
    matrix1 = readMatrixFromFile(file1, &rows1, &cols1);
    printf("Первая матрица (%dx%d):\n", rows1, cols1);
    printMatrix(matrix1, rows1, cols1);
    printf("\n");
    
    // Чтение второй матрицы
    matrix2 = readMatrixFromFile(file2, &rows2, &cols2);
    printf("Вторая матрица (%dx%d):\n", rows2, cols2);
    printMatrix(matrix2, rows2, cols2);
    printf("\n");
    
    // Умножение матриц
    int resultRows, resultCols;
    result = multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, &resultRows, &resultCols);
    
    printf("Результат умножения (%dx%d):\n", resultRows, resultCols);
    printMatrix(result, resultRows, resultCols);
    printf("\n");
    
    // Запись результата в файл
    writeMatrixToFile(result, resultRows, resultCols, resultFile);
    printf("Результат записан в файл %s\n", resultFile);
    
    // Освобождение памяти
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(result, resultRows);
    
    return 0;
}