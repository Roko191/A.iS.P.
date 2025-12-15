#include <bits/time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

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
