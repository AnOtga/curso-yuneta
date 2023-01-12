#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int n;

    if (argc < 2) {
        n = 100;
    }
    else {
        n = atoi(argv[1]);
    }

    if (n <= 0) {
        printf("Invalid argument.");
    }

    clock_t clockEnd;
    clock_t clockStart = clock();

    for (size_t i = 0; i < n; i++)
    {
        printf("Hello world\n");
    }

    clockEnd = clock();
    printf("Time elapsed: %.2f seconds\n", (double)(clockEnd - clockStart) / CLOCKS_PER_SEC);
    printf("Lines printed: %.i\n", n);

    return 0;
}