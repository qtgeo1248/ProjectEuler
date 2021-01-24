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

    int m = 1; int n = 1;
    for (char c = fgetc(f); c != '\n'; c = fgetc(f))
        if (c == ' ')
            n++;
    while (getline(&line, &len, f) != -1)
        m++;
    fclose(f);
    f = fopen(filename, "r");
    

    fclose(f);
    return 0;
}