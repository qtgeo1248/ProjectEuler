#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool is_div(size_t big, size_t div) {
    for (size_t i = 1; i <= div; i++)
        if (big % i != 0)
            return false;
    return true;
}

int main() {
    char *filename = "num.txt";
    FILE *f = fopen(filename, "r");
    char *line = NULL; size_t len = 0; char *thing = NULL;
    getline(&line, &len, f);
    size_t max = strtol(line, &thing, 10);

    bool isDone = false;
    size_t tmp = 20;
    while (!isDone) {
        tmp++;
        isDone = is_div(tmp, max);
    }
    printf("Answer: %zu\n", tmp);
    free(line);
    fclose(f);
    return 0;
}