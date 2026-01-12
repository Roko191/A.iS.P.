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

// Quick sort
static inline void swap(int32_t* a, int32_t* b)
{
    int32_t tmp = *a;
    *a = *b;
    *b = tmp;
}

static void insertionSortRange(int32_t* nums, int left, int right)
{
    for (int i = left + 1; i <= right; i++) {
        int32_t key = nums[i];
        int j = i - 1;

        while (j >= left && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

static int partition(int32_t* nums, int left, int right)
{
    int32_t pivot = nums[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }

    swap(&nums[i + 1], &nums[right]);
    return i + 1;
}


#define QS_CUTOFF 20

static void quickSortRec(int32_t* nums, int left, int right)
{
    if (left >= right)
        return;

    if (right - left + 1 <= QS_CUTOFF) {
        insertionSortRange(nums, left, right);
        return;
    }

    int pivotIndex = partition(nums, left, right);

    quickSortRec(nums, left, pivotIndex - 1);
    quickSortRec(nums, pivotIndex + 1, right);
}


void quickSort(const int32_t_v* vector, int32_t_v** sorted_arr)
{
    int32_t_v* arr = malloc(sizeof(int32_t_v));
    if (!arr)
        return;

    if (int32_t_v_copy(arr, vector) != 0) {
        free(arr);
        return;
    }

    if (arr->size > 1) {
        quickSortRec(arr->nums, 0, arr->size - 1);
    }

    *sorted_arr = arr;
}

// Shell sort
static void shellSortInPlace(int32_t* nums, size_t size)
{
    for (size_t gap = size / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < size; i++) {
            int32_t temp = nums[i];
            ssize_t j = i;

            while (j >= (ssize_t)gap && nums[j - gap] > temp) {
                nums[j] = nums[j - gap];
                j -= gap;
            }
            nums[j] = temp;
        }
    }
}


void shellSort(const int32_t_v* vector, int32_t_v** sorted_arr)
{
    int32_t_v* arr = malloc(sizeof(int32_t_v));
    if (!arr)
        return;

    if (int32_t_v_copy(arr, vector) != 0) {
        free(arr);
        return;
    }

    if (arr->size > 1) {
        shellSortInPlace(arr->nums, arr->size);
    }

    *sorted_arr = arr;
}

// Merge sort
static void merge(int32_t* nums, int32_t* tmp,
                  int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }

    while (i <= mid)
        tmp[k++] = nums[i++];

    while (j <= right)
        tmp[k++] = nums[j++];

    for (i = left; i <= right; i++)
        nums[i] = tmp[i];
}


static void mergeSortRec(int32_t* nums, int32_t* tmp,
                         int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSortRec(nums, tmp, left, mid);
    mergeSortRec(nums, tmp, mid + 1, right);
    merge(nums, tmp, left, mid, right);
}


void mergeSort(const int32_t_v* vector, int32_t_v** sorted_arr)
{
    int32_t_v* arr = malloc(sizeof(int32_t_v));
    if (!arr)
        return;

    if (int32_t_v_copy(arr, vector) != 0) {
        free(arr);
        return;
    }

    if (arr->size > 1) {
        int32_t* tmp = malloc(arr->size * sizeof(int32_t));
        if (!tmp) {
            free(arr->nums);
            free(arr);
            return;
        }

        mergeSortRec(arr->nums, tmp, 0, arr->size - 1);
        free(tmp);
    }

    *sorted_arr = arr;
}


