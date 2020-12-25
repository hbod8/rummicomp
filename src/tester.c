#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <malloc.h>

#include "models/headers.h"

int main() {
    printf("test test test ------- test test test\n");
    struct tile b6 = {1, 6}; //blue 6
    struct tile b7 = {1, 7}; //blue 7
    struct tile b8 = {1, 8}; //blue 8
    struct tile b9 = {1,9}; //blue 9

    struct tile bl6 = {0, 6}; //black 6
    struct tile bu6 = {1, 6}; //blue 6
    struct tile r6 = {2, 6}; //red 6
    struct tile o6 = {3, 6}; //orange 6
    
    struct run r12 = {&b8, NULL};
    struct run r11 = {&b7, &r12};
    struct run r1 = {&b6, &r11};
    struct run r2 = {&b9, &r1};

    
    printf("\n %d", length(&r2));
    
}