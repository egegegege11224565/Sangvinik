#include <stdio.h>

//Напишите программу, для вычисления объема пересечения двух прямоугольных параллелепипедов, грани которых параллельны осям координат.
//Вычисление объема реализовать через отдельную функцию, в которую передавать структуры обязательно по адресу.

struct point{
    float x, y, z;
};

struct Box{
    struct point min; //точка с минимальными координатами параллелепипеда
    struct point max; //точка с максимальными координатами параллелепипеда
};


float intersection_volume(const struct Box *box1, const struct Box *box2) {
    float overlap_min_x, overlap_max_x, width;
    float overlap_min_y, overlap_max_y, height;
    float overlap_min_z, overlap_max_z, depth;
    
    if (box1->min.x > box2->min.x) {
        overlap_min_x = box1->min.x;
    } else {
        overlap_min_x = box2->min.x;
    }
    
    if (box1->max.x < box2->max.x) {
        overlap_max_x = box1->max.x;
    } else {
        overlap_max_x = box2->max.x;
    }
    width = overlap_max_x - overlap_min_x;
    
    if (box1->min.y > box2->min.y) {
        overlap_min_y = box1->min.y;
    } else {
        overlap_min_y = box2->min.y;
    }
    
    if (box1->max.y < box2->max.y) {
        overlap_max_y = box1->max.y;
    } else {
        overlap_max_y = box2->max.y;
    }
    height = overlap_max_y - overlap_min_y;
    
    if (box1->min.z > box2->min.z) {
        overlap_min_z = box1->min.z;
    } else {
        overlap_min_z = box2->min.z;
    }
    
    if (box1->max.z < box2->max.z) {
        overlap_max_z = box1->max.z;
    } else {
        overlap_max_z = box2->max.z;
    }
    depth = overlap_max_z - overlap_min_z;
    
    if (width > 0 && height > 0 && depth > 0) {
        return width * height * depth;
    }
    
    return 0.0;
}

void print_box(const struct Box *box, const char *name) {
    printf("%s параллелепипед:\n", name);
    printf("  min точка: (%.1f, %.1f, %.1f)\n", box->min.x, box->min.y, box->min.z);
    printf("  max точка: (%.1f, %.1f, %.1f)\n", box->max.x, box->max.y, box->max.z);
}

int main() {
    struct Box box1 = { {-1.0, -1.0, -1.0}, {7.0, 7.0, 7.0} };
    
    struct Box box2 = { {-1.0, -1.0, -1.0}, {10.0, 10.0, 10.0} };
    
    printf("Программа для вычисления объема пересечения двух параллелепипедов\n");
    printf("Грани параллелепипедов параллельны осям координат\n\n");
    
    print_box(&box1, "Первый");
    print_box(&box2, "Второй");
    printf("\n");
    
    float volume = intersection_volume(&box1, &box2);
    
    printf("Объем пересечения параллелепипедов: %.3f\n", volume);
    
    return 0;
}