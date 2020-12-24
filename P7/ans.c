#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main() {
    char *filename = "num.txt";
    FILE *f = fopen(filename, "r");
    char *line = NULL; size_t len = 0; char *thing = NULL;
    getline(&line, &len, f);
    size_t max = strtol(line, &thing, 10);

    size_t *primes = calloc(sizeof(size_t), max);
    size_t num = 0;
    for (size_t test = 2; num < max; test++) {
        bool isPrime = true;
        for (size_t i = 0; i < num; i++)
            if (test % primes[i] == 0)
                isPrime = false;
        if (isPrime) {
            primes[num] = test;
            num++;
        }
    }
    printf("Answer: %zu\n", primes[max - 1]);
    free(primes);
    free(line);
    fclose(f);
    return 0;
}