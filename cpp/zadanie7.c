#include <stdio.h>
// Напишите программу, для вычисления объема пересечения двух прямоугольных параллелепипедов, грани которых параллельны осям координат.
struct point{
    float x, y, z;
};

struct Box{
    struct point min; //точка с минимальными координатами параллелепипеда
    struct point max; //точка с максимальными координатами параллелепипеда
};

float funk(struct Box *b1, struct Box *b2);

int main(){

    struct Box b1 = {{0, 0, 0}, {10, 10, 10}};
    struct Box b2 = {{10, 10, 10}, {11, 11, 11}};
    
    float gh = funk(&b1, &b2);
    printf("V = %f\n", gh);
    return 0;
}

float funk(struct Box *b1, struct Box *b2){
    
    float start, end, dx, dy, dz;

    if(b1->min.x > b2->min.x){
        start = b1->min.x;
    }else{
        start = b2->min.x;
    }

    if(b1->max.x < b2->max.x){
        end = b1->max.x;
    }else{
        end = b2->max.x;
    }

    dx = end - start;

    if(b1->min.y > b2->min.y){
        start = b1->min.y;
    }else{
        start = b2->min.y;
    }

    if(b1->max.y < b2->max.y){
        end = b1->max.y;
    }else{
        end = b2->max.y;
    }

    dy = end - start;

    if(b1->min.z > b2->min.z){
        start = b1->min.z;
    }else{
        start = b2->min.z;
    }

    if(b1->max.z < b2->max.z){
        end = b1->max.z;
    }else{
        end = b2->max.z;
    }

    dz = end - start;

    if(dx <= 0 || dy <= 0 || dz <= 0){
        return 0;
    }

    float V = dx * dy * dz;

    return V;
}