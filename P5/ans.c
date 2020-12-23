#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

size_t gcd(size_t a, size_t b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a <= b) return gcd(a, b - a * (b / a));
    else return gcd(a - b * (a / b), b);
}

int main() {
    char *filename = "num.txt";
    FILE *f = fopen(filename, "r");
    char *line = NULL; size_t len = 0; char *thing = NULL;
    getline(&line, &len, f);
    size_t max = strtol(line, &thing, 10);

    size_t lcm = 1;
    for (size_t i = 1; i <= max; i++)
        lcm *= i / gcd(i, lcm);
    printf("Answer: %zu\n", lcm);
    return 0;
}