#include <stdio.h>
#include <stdint.h>

uint8_t transform (int i, uint8_t byte){ 
    if (byte == 0){
        return 0;
    }  
    else {
        if (i%2 == 0){
            return byte*byte;
        }
        else{
            return (byte - 1);
        }
    }
    
};

union digit{
    uint64_t digit;
    uint8_t bytes[8];
};

union digit tr_digit(union digit num){
    for (int i = 0; i < 8; i++){

        num.bytes[i]=transform(i, num.bytes[i]);
    }
    return num;
};

void show (union digit num){
    for (int i = 0; i < 8; i++){
        printf("%d;  ", num.bytes[i]);
    }
    printf("\n");
}

int main() {
    union digit num;
    printf("Введите целое 64-битное число\n");
    scanf("%lld", &num.digit);
    show(num);
    num = tr_digit(num);
    show(num);
    printf("Результат: %lld\n", num.digit);
    return 0;
}