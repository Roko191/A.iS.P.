#pragma once

#include <stdio.h>

typedef struct Node {
    float el;
    struct Node* next;
} Node;


FILE* getFile(const char* path);
int readFileAndCalculate(FILE* file);