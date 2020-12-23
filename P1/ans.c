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
    for (size_t i = 0; i < max; i++)
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    printf("Answer: %zu\n", sum);
    free(line);
    fclose(f);
    return 0;
}