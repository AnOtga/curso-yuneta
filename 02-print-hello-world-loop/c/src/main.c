#include <argp.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>

static inline struct timespec ts_diff (struct timespec start, struct timespec end)
{
    struct timespec temp;
    if ((end.tv_nsec - start.tv_nsec) < 0) {
        temp.tv_sec = end.tv_sec - start.tv_sec - 1;
        temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec - start.tv_sec;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    return temp;
}

int main(int argc, char* argv[])
{
    uint64_t n;
    struct timespec st, et, tt;

    if (argc < 2) {
        n = 100;
    }
    else {
        n = atoi(argv[1]);
    }

    if (n <= 0) {
        printf("Invalid argument.");
    }

    clock_gettime(CLOCK_MONOTONIC, &st);

    for (size_t i = 0; i < n; i++) {
        printf("Hello world\n");
    }

    clock_gettime(CLOCK_MONOTONIC, &et);

    tt = ts_diff(st, et);
    printf("Time elapsed: %lu.%lus seconds\n", tt.tv_sec, tt.tv_nsec);
    printf("Lines printed: %lu\n", n);

    return 0;
}
