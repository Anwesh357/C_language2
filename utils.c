#include <stdio.h>
#include "utils.h"

int getIntInput() {
    int x;
    scanf("%d", &x);
    return x;
}

float getFloatInput() {
    float x;
    scanf("%f", &x);
    return x;
}

void getStringInput(char *str, int size) {
    scanf("%s", str);
}