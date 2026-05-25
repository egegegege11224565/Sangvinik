#include <stdio.h>
#include <stdint.h>
#include <math.h>


uint8_t transform (uint8_t byte){
    if (byte%2 == 0){
        return pow(byte, 2);
    }
    else{
        return byte - 1; 
    }
}

union digit
{
    uint64_t digit;
    uint8_t bytes[8];
};


union digit transform_digit (union digit a){
    for (int i = 0; i < 8; i++){
        a.bytes[i] = transform(a.bytes[i]);
    }
    return a;
}

void show_bytes (union digit a){
    for (int i = 0; i < 8; i++){
        printf("%d ", a.bytes[i]);
    }
    printf("\n");
}

int main()
{
    union digit a;
    printf("Введите 64-битное число:\n");
    scanf("%lld", &a.digit);
    show_bytes(a);
    a = transform_digit(a);
    show_bytes(a);
    printf("Преобразованное число: %lld\n", a.digit);
    return 0;
}
