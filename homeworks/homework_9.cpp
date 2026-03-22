#include <stdio.h>
#include <stdlib.h>

void task6();
void task7();

double** allocate_matrix(int rows, int cols);
void free_matrix_manual(double** m, int rows);
bool is_power_of(long long n, int base);

int main() {
    int task_num;
    printf("Виберіть номер завдання (6 або 7): ");
    if (scanf("%d", &task_num) != 1) return 1;

    switch (task_num) {
        case 6: task6(); break;
        case 7: task7(); break;
        default: printf("Завдання не знайдено.\n");
    }
    return 0;
}

// Функції для роботи з матрицями (Завдання 6)
double** allocate_matrix(int rows, int cols) {
    double** m = (double**)malloc(rows * sizeof(double*));
    if (m == NULL) return NULL;
    for (int i = 0; i < rows; i++) {
        m[i] = (double*)calloc(cols, sizeof(double));
    }
    return m;
}

void free_matrix_manual(double** m, int rows) {
    if (m != NULL) {
        for (int i = 0; i < rows; i++) {
            free(m[i]);
        }
        free(m);
    }
}

// Перевірка на ступінь (Завдання 7)
bool is_power_of(long long n, int base) {
    if (n <= 0) return false;
    if (n == 1) return true;
    while (n % base == 0) {
        n /= base;
    }
    return n == 1;
}

void task6() {
    int count;
    printf("Введіть кількість матриць у масиві: ");
    scanf("%d", &count);

    // Масиви для зберігання адрес матриць та їх розмірів
    double*** matrix_list = (double***)malloc(count * sizeof(double**));
    int* rows_list = (int*)malloc(count * sizeof(int));
    int* cols_list = (int*)malloc(count * sizeof(int));

    bool same_size = true;

    for (int k = 0; k < count; k++) {
        printf("\nМатриця №%d. Розміри (рядки стовпці): ", k + 1);
        scanf("%d %d", &rows_list[k], &cols_list[k]);

        matrix_list[k] = allocate_matrix(rows_list[k], cols_list[k]);

        printf("Введіть елементи (%d x %d):\n", rows_list[k], cols_list[k]);
        for (int i = 0; i < rows_list[k]; i++) {
            for (int j = 0; j < cols_list[k]; j++) {
                scanf("%lf", &matrix_list[k][i][j]);
            }
        }

        // Перевірка на однаковість розмірів з першою матрицею
        if (k > 0) {
            if (rows_list[k] != rows_list[0] || cols_list[k] != cols_list[0]) {
                same_size = false;
            }
        }
    }

    // Створення та обчислення сумарної матриці
    if (same_size && count > 0) {
        int R = rows_list[0];
        int C = cols_list[0];
        double** total_sum = allocate_matrix(R, C);

        for (int k = 0; k < count; k++) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    total_sum[i][j] += matrix_list[k][i][j];
                }
            }
        }

        printf("\nСума всіх матриць:\n");
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) printf("%8.2lf ", total_sum[i][j]);
            printf("\n");
        }
        free_matrix_manual(total_sum, R);
    } else {
        printf("\nМатриці мають різні розміри, сумування неможливе.\n");
    }

    // очищення виділеної пам'яті
    for (int k = 0; k < count; k++) {
        free_matrix_manual(matrix_list[k], rows_list[k]);
    }
    free(matrix_list);
    free(rows_list);
    free(cols_list);
}

void task7() {
    int n;
    printf("Введіть кількість натуральних чисел n: ");
    scanf("%d", &n);

    long long *arr = (long long*)malloc(n * sizeof(long long));
    int p2 = 0, p3 = 0;

    printf("Введіть %d натуральних чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if (is_power_of(arr[i], 2)) p2++;
        if (is_power_of(arr[i], 3)) p3++;
    }

    printf("Результат:\nСтупенів двійки: %d\nСтупенів трійки: %d\n", p2, p3);

    free(arr);
}
