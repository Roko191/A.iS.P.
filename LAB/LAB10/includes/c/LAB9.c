#include <bits/time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#include "../LAB9.h"

uint32_t genSeed(int verbose, int debug){
    uint32_t s_seed = 0;

    if(debug){
        if(verbose) printf("Debug mode enabled using constant for seed\n");
        return s_seed;
    }

    int s_fd_urandom = open("/dev/urandom", O_RDONLY);
    if(s_fd_urandom == -1){
        perror("[WARN] Failed to open /dev/uranom: ");
    } else {
        if(verbose) printf("[VERBOSE] /dev/urandom opened succesfully\n");
    }

    // We dont need to crash if /dev/urandom fails to open
    if(s_fd_urandom >= 0) read(s_fd_urandom, &s_seed, sizeof(s_seed));
    
    s_seed += time(NULL) + getpid();

    if(verbose) printf("[VERBOSE] seed: %u\n", s_seed);

    close(s_fd_urandom);

    return s_seed;
}

uint64_t now_ms(){
    struct timespec vrime;
    clock_gettime(CLOCK_MONOTONIC_RAW, &vrime);
    return (uint64_t)vrime.tv_sec * 1000LL + (uint64_t)vrime.tv_nsec / 1000000;
}

int createArrayWithRandomNums(int count, int32_t_v** vector){
    int32_t_v* tmpVector = malloc(sizeof(int32_t_v));
    if (!tmpVector) {
        return 2;
    }
    tmpVector->nums = malloc(count * sizeof(int32_t));
    if(!tmpVector->nums){
        return 1;
    }
    tmpVector->capacity = count;
    tmpVector->size = count;

    for(int i = 0; i < count; i++){
        tmpVector->nums[i] = rand() % 1001;
    }

    *vector = tmpVector;

    return 0;
}

int int32_t_v_copy(int32_t_v* dst, const int32_t_v* src)
{
    if (!dst || !src)
        return -1;

    dst->nums = malloc(src->capacity * sizeof(int32_t));
    if (!dst->nums)
        return -1;

    memcpy(dst->nums, src->nums, src->size * sizeof(int32_t));

    dst->size = src->size;
    dst->capacity = src->capacity;

    return 0;
}


void printArray(const int32_t_v* vector){
    if(!vector) return;
    
    printf("[");
    for(int i=0; i < vector->size; i++){
        if(i == vector-> size - 1){
            printf("%d", vector->nums[i]);
            break;
        }
        printf("%d, ", vector->nums[i]);
    }
    printf("]\n");
}