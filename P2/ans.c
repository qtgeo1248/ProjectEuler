#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char *filename = "num.txt";
    FILE *f = fopen(filename, "r");
    char *line = NULL; size_t len = 0; char *tmp = NULL;
    getline(&line, &len, f);
    size_t max = strtol(line, &tmp, 10);
    size_t sum = 0;
    size_t f1 = 1; size_t f2 = 2;
    while (f1 <= max) {
        if (f1 % 2 == 0) sum += f1;
        size_t tmp = f2;
        f2 += f1;
        f1 = tmp;
    }
    printf("Answer: %zu\n", sum);
    free(line);
    fclose(f);
    return 0;
}