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

    size_t sumsq = 0;
    size_t sqsum = 0;
    for (size_t i = 1; i <= max; i++) {
        sumsq += i * i;
        sqsum += i;
    }
    sqsum *= sqsum;
    printf("Answer: %zu\n", sqsum - sumsq);
    return 0;
}