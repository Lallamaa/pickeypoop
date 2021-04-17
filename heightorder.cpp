#include <stdio.h>
#include <stdlib.h>

#define COUNT 20

void read(int* arr) {
    int i;

    for (i = 0; i < COUNT; i++) {
      scanf("%d", arr + i);
    }
}

int inversions(int* arr) {
    int count = 0;
    int i, j;

    for (i = 0; i < COUNT - 1; i++) {
        for (j = i + 1; j < COUNT; j++) {
            if (*(arr + i) > *(arr + j)) count++;
        }
    }
    return count;
}

int steps(int* arr) {
    read(arr);
    return inversions(arr);
}

int main() {
    int n, line;

    scanf("%d", &n);
    int* arr = (int*)malloc(COUNT * sizeof(int));

    while (n-- > 0) {
        scanf("%d", &line);
        printf("%d %d\n", line, steps(arr));
    }

    free(arr);
    return 0;
}