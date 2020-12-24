#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *filename = "num.txt";
    FILE *f = fopen(filename, "r");
    char *line = NULL; size_t len = 0; char *thing = NULL;
    getline(&line, &len, f);
    size_t sum = strtol(line, &thing, 10);

    for (size_t a = 1; a < sum; a++)
        for (size_t b = a + 1; b < sum; b++) {
            size_t c = 1000 - a - b;
            if (c * c == a * a + b * b)
                printf("Answer: %zu\n", a * b * c);
        }

    fclose(f);
    free(line);
    return 0;
}