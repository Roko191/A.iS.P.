#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef struct int32_t_vector {
    int32_t* nums;
    size_t size;
    size_t capacity;
} int32_t_v;

// GENERAL
uint32_t genSeed(int verbose, int debug);
uint64_t now_ms();

// Vector stuff
int int32_t_v_copy(int32_t_v* dst, const int32_t_v* src);
int createArrayWithRandomNums(int count, int32_t_v** vector);
void printArray(const int32_t_v* vector);


// Sorting alghoritams
void bubbleSort(const int32_t_v* arr, int32_t_v** sorted_arr);
void exchangeSort(const int32_t_v* arr, int32_t_v** sorted_arr);
void selectionSort(const int32_t_v* arr, int32_t_v** sorted_arr);
void insertionSort(const int32_t_v* arr, int32_t_v** sorted_arr);
void quickSort(const int32_t_v* arr, int32_t_v** sorted_arr);
void shellSort(const int32_t_v* vector, int32_t_v** sorted_arr);
void mergeSort(const int32_t_v* vector, int32_t_v** sorted_arr);