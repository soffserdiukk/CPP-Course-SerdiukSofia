#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

void task1();
void task2();
void task3();
void task4();
void task9();

int input_array(int *arr);
double* create_vector(int n);
void free_vector(double* v);
double** create_matrix(int n);
void free_matrix(double** m, int n);

int main() {
    int task_num;
    printf("Виберіть номер завдання (1-4 або 9): ");
    if (scanf("%d", &task_num) != 1) return 1;

    switch (task_num) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 9: task9(); break;
        default: printf("Завдання не знайдено.\n");
    }
    return 0;
}

void task1() {
    int n;
    double sum = 0.0;

    printf("Введіть кількість елементів n: ");
    scanf("%d", &n);

    double* arr = (double*)malloc(n * sizeof(double));

    // Перевірка, чи дали пам'ять
    if (arr == NULL) {
        printf("Помилка: не вдалося виділити пам'ять!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Елемент [%d] = ", i);
        scanf("%lf", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i] * arr[i];
    }

    printf("\nРезультат: Сума квадратів = %.4lf\n", sum);

    free(arr);
    printf("Пам'ять успішно звільнено.\n");
}

int input_array(int *arr) {
    int count = 0;
    int num;

    printf("Вводьте цілі числа (0 - для завершення):\n");

    while (count < MAX_SIZE) {
        printf("Елемент [%d]: ", count);
        scanf("%d", &num);

        if (num == 0) break;

        arr[count] = num;
        count++;
    }
    return count;
}

void task2() {
    int numbers[MAX_SIZE];
    int n = input_array(numbers);

    int squares_count = 0;
    int cubes_count = 0;


    for (int i = 0; i < n; i++) {
        int val = abs(numbers[i]);

        double s_root = sqrt((double)val);
        if (s_root == (int)s_root) {
            squares_count++;
        }

        double c_root = cbrt((double)val);
        if (fabs(c_root - round(c_root)) < 0.000001) {
            cubes_count++;
        }
    }

    printf("Кількість введених чисел: %d\n", n);
    printf("Повних квадратів: %d\n", squares_count);
    printf("Повних кубів: %d\n", cubes_count);
}

void task3() {
    int n, m;
    printf("Введіть кількість рядків (n) та стовпців (m): ");
    scanf("%d %d", &n, &m);

    // 1. Виділяємо пам'ять під масив вказівників на рядки
    // int** — це "вказівник на вказівник"
    int **matrix = (int**)malloc(n * sizeof(int*));

    // 2. Для кожного рядка виділяємо пам'ять під m цілих чисел
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
    }

    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // 4. Пошук мінімального елемента
    int min = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }

    printf("\nМінімальний елемент у матриці: %d\n", min);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    printf("Пам'ять матриці успішно звільнено.\n");
}

// Функція для створення та введення вектора
double* create_vector(int n) {
    double* v = (double*)malloc(n * sizeof(double));
    if (v == NULL) return NULL;

    for (int i = 0; i < n; i++) {
        printf("  Елемент [%d]: ", i);
        scanf("%lf", &v[i]);
    }
    return v;
}

// Функція для очищення пам'яті
void free_vector(double* v) {
    free(v);
}

double** create_matrix(int n) {
    double** m = (double**)malloc(n * sizeof(double*));
    if (m == NULL) return NULL;

    for (int i = 0; i < n; i++) {
        // calloc виділяє пам'ять і ОДРАЗУ заповнює її нулями
        m[i] = (double*)calloc(n, sizeof(double));
    }
    return m;
}

void free_matrix(double** m, int n) {
    for (int i = 0; i < n; i++) free(m[i]);
    free(m);
}

// завдання на добуток матриць
void task4() {
    int n;
    printf("Розмір квадратних матриць n: ");
    scanf("%d", &n);

    double** A = create_matrix(n);
    double** B = create_matrix(n);
    double** C = create_matrix(n);

    printf("Введіть матрицю A:\n");
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%lf", &A[i][j]);

    printf("Введіть матрицю B:\n");
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%lf", &B[i][j]);

    // Обчислення добутку (рядок на стовпчик)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nРезультат множення:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%7.2lf ", C[i][j]);
        printf("\n");
    }

    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);
}

void task9() {
    int n, m_cols, k, insert_pos;
    printf("Введіть кількість рядків (N) та стовпців (M): ");
    scanf("%d %d", &n, &m_cols);

    // 1. Створення початкової матриці
    double **matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(m_cols * sizeof(double));
        for (int j = 0; j < m_cols; j++) {
            matrix[i][j] = (double)(rand() % 100) / 10.0; // Випадкові дійсні числа
        }
    }

    printf("\nПочаткова матриця:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m_cols; j++) printf("%6.1lf ", matrix[i][j]);
        printf("\n");
    }

    printf("\nСкільки стовпців додати (k)? ");
    scanf("%d", &k);
    printf("Починаючи з якого номера стовпця (0-%d)? ", m_cols);
    scanf("%d", &insert_pos);

    if (insert_pos < 0) insert_pos = 0;
    if (insert_pos > m_cols) insert_pos = m_cols;

    // 2. Додавання стовпців
    for (int i = 0; i < n; i++) {
        // Збільшуємо розмір кожного рядка
        double* temp = (double*)realloc(matrix[i], (m_cols + k) * sizeof(double));
        if (temp == NULL) {
            printf("Помилка перерозподілу пам'яті!\n");
            return;
        }
        matrix[i] = temp;

        // Зсуваємо елементи вправо, щоб звільнити місце
        for (int j = m_cols - 1; j >= insert_pos; j--) {
            matrix[i][j + k] = matrix[i][j];
        }

        // Заповнюємо нові стовпці 0
        for (int j = insert_pos; j < insert_pos + k; j++) {
            matrix[i][j] = 0.0;
        }
    }

    m_cols += k;

    printf("\nМатриця після додавання стовпців:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m_cols; j++) printf("%6.1lf ", matrix[i][j]);
        printf("\n");
    }

    // Звільнення пам'яті
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
}
