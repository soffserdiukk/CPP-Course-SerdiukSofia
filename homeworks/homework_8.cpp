#include <stdio.h>

#define MAX_SIZE 25

int main() {
    int n, size;
    double A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE];

    printf("Введіть n (розмірність матриці буде 2n+1): ");
    if (scanf("%d", &n) != 1 || (2 * n + 1) > MAX_SIZE) {
        printf("Некоректне значення n.\n");
        return 1;
    }

    size = 2 * n + 1;

    printf("Введіть елементи матриці %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &A[i][j]);
            B[i][j] = A[i][j];
        }
    }

    // 2. Логіка повороту блоків на 90 градусів за годинниковою стрілкою
    // Блоки обмежені головною (i=j) та побічною (i+j=size-1) діагоналями
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < size - 1 - i; j++) {
            // Верхній сектор переходить у Правий
            B[j][size - 1 - i] = A[i][j];

            // Правий сектор переходить у Нижній
            B[size - 1 - i][size - 1 - j] = A[j][size - 1 - i];

            // Нижній сектор переходить у Лівий
            B[size - 1 - j][i] = A[size - 1 - i][size - 1 - j];

            // Лівий сектор переходить у Верхній
            B[i][j] = A[size - 1 - j][i];
        }
    }

    printf("\nМатриця після повороту блоків:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%6.1f ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}