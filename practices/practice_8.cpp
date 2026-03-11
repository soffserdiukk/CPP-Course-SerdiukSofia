#include <stdio.h>
#define MAX_SIZE 10

void task1(); void task2(); void task3(); void task4();
void task5(); void task6(); void task7();

double calculate_determinant(double matrix[MAX_SIZE][MAX_SIZE], int n);

int main() {
    int task_num;
    printf("--- ПРАКТИЧНА РОБОТА 8: БАГАТОВИМІРНІ МАСИВИ ---\n");
    printf("Виберіть номер завдання (1-7): ");
    if (scanf("%d", &task_num) != 1) return 1;

    switch (task_num) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        default: printf("Завдання не знайдено.\n");
    }
    return 0;
}

// 1) Заміна елемента рівного M на число N у матриці 3x3
void task1() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n_val, m_val;
    printf("Введіть N (нове число) та M (яке замінити): ");
    scanf("%d %d", &n_val, &m_val);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == m_val) matrix[i][j] = n_val;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 2) Заміна елемента за індексами i, j на число a (з перевіркою)
void task2() {
    double matrix[3][3] = {{1.0, 2.3, 3.0}, {4.5, 6.0, 7.0}, {8.0, 9.0, 10.0}};
    int row, col;
    double a_val;
    printf("Введіть індекси i, j (0-2) та нове число a: ");
    scanf("%d %d %lf", &row, &col, &a_val);

    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        matrix[row][col] = a_val;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) printf("%.1f ", matrix[i][j]);
            printf("\n");
        }
    } else {
        printf("Помилка: Некоректні індекси!\n");
    }
}

// 3) Ввід матриці m x n (m, n < 20) з підказкою для кожного елемента
void task3() {
    int m, n;
    double matrix[20][20];
    printf("Введіть m та n (до 20): ");
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Елемент [%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    printf("Матриця введена успішно.\n");
}

// 4) Ввід матриці m x n рядком (через пробіл)
void task4() {
    int m, n;
    double matrix[25][25];
    printf("Введіть m та n (до 25): ");
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        printf("Рядок %d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    printf("Готово.\n");
}

// 5) Транспонування квадратної матриці
void task5() {
    int n;
    double matrix[10][10], temp;
    printf("Розмір квадратної матриці n: ");
    scanf("%d", &n);

    printf("Введіть матрицю:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%lf", &matrix[i][j]);

    // Транспонування (обмін елементів симетрично діагоналі)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    printf("Транспонована матриця:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%.1f ", matrix[i][j]);
        printf("\n");
    }
}

// 6) Сума елементів A[i,j], для яких i - j = k
void task6() {
    int n, m, k;
    double matrix[100][100], sum = 0;
    bool found = false;

    printf("Введіть N, M та ціле k: ");
    scanf("%d %d %d", &n, &m, &k);

    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
            if (i - j == k) {
                sum += matrix[i][j];
                found = true;
            }
        }
    }
    printf("Результат: %.2f\n", found ? sum : 0.0);
}

// 7) Детермінант квадратної матриці (через рекурсію)
void task7() {
    int n;
    double matrix[MAX_SIZE][MAX_SIZE];
    printf("Розмір матриці n для детермінанта: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%lf", &matrix[i][j]);

    printf("Детермінант: %.4f\n", calculate_determinant(matrix, n));
}

double calculate_determinant(double matrix[MAX_SIZE][MAX_SIZE], int n) {
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double det = 0;
    double submatrix[MAX_SIZE][MAX_SIZE];
    int sign = 1;

    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det += sign * matrix[0][x] * calculate_determinant(submatrix, n - 1);
        sign = -sign;
    }
    return det;
}