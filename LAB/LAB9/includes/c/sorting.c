#include "../LAB9.h"
#include <stdint.h>

void bubbleSort(const int32_t_v* vector, int32_t_v** sorted_arr)
{
    int32_t_v* arr = malloc(sizeof(int32_t_v));
    int32_t_v_copy(arr, vector);


    for (int i = 0; i < arr->size - 1; i++)
    {

        // Last i elements are already in place, so the loop will only num n - i - 1 times
        for (int j = 0; j < arr->size - i - 1; j++)
        {
            if (arr->nums[j] > arr->nums[j + 1]){
                int temp = arr->nums[j];
                arr->nums[j] = arr->nums[j + 1];
                arr->nums[j + 1] = temp;
            }
        }
    }

    *sorted_arr = arr;
}

void exchangeSort(const int32_t_v* vector, int32_t_v** sorted_arr)
{
    int32_t_v* arr = malloc(sizeof(int32_t_v));
    int32_t_v_copy(arr, vector);

    int i, j, temp;
    for (i = 0; i < arr->size - 1; i++) {
        // Outer Loop
        for (j = i + 1; j < arr->size; j++) {
            // Inner Loop
            // Sorting into ascending order if
            // previous element bigger than next
            // element we swap to make it in ascending order
            if (arr->nums[i] > arr->nums[j]) {
                // Swapping
                temp = arr->nums[i];
                arr->nums[i] = arr->nums[j];
                arr->nums[j] = temp;
            }
        }
    }

    *sorted_arr = arr; 
}

void selectionSort(const int32_t_v* vector, int32_t_v** sorted_arr) {
    
    int32_t_v* arr = malloc(sizeof(int32_t_v));
    int32_t_v_copy(arr, vector);

    // Start with the whole array as unsored and one by
  	// one move boundary of unsorted subarray towards right
    for (int i = 0; i < arr->size - 1; i++) {

        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < arr->size; j++) {
            if (arr->nums[j] < arr->nums[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first
        // element in the unsorted part
        int temp = arr->nums[min_idx];
        arr->nums[min_idx] = arr->nums[i];
        arr->nums[i] = temp;
    }

    *sorted_arr = arr;
}

void insertionSort(const int32_t_v* vector, int32_t_v** sorted_arr)
{
    int32_t_v* arr = malloc(sizeof(int32_t_v));
    int32_t_v_copy(arr, vector);

    // Starting from the second element
    for (int i = 1; i < arr->size; i++)
    {
        int key = arr->nums[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are
        // greater than key, to one position to
        // the right of their current position
        while (j >= 0 && arr->nums[j] > key)
        {
            arr->nums[j + 1] = arr->nums[j];
            j = j - 1;
        }

        // Move the key to its correct position
        arr->nums[j + 1] = key;
    }

    *sorted_arr = arr;
}

