#include <stdio.h>
#include <math.h>

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();

void input_vector(double vec[], int n);
void print_vector(double vec[], int n);
void sum_vectors(const double v1[], const double v2[], double res[], int n);
double scalar_product(const double v1[], const double v2[], int n);

int main() {
    int task_num;
    printf("Виберіть номер завдання (1-7): ");
    scanf("%d", &task_num);

    switch (task_num) {
        case 1:  task1();  break;
        case 2:  task2();  break;
        case 3:  task3();  break;
        case 4:  task4();  break;
        case 5:  task5();  break;
        case 6:  task6();  break;
        case 7:  task7();  break;
    }
    return 0;
}

void task1() {
    int arr[5] = {5, 18, 2, 33, 9};
    float limit;
    int counter = 0;
    printf("Введіть дійсне число: ");
    scanf("%f", &limit);
    for (int i = 0; i < 5; i++) {
        if (arr[i] < limit) counter++;
    }
    printf("Результат: %d чисел менші за %.2f\n", counter, limit);
}

void task2() {
    int numbers[4] = {5, 112, 4, 3};
    printf("Елементи навпаки: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d%s", numbers[i], (i > 0) ? ", " : "");
    }
    printf("\n");
}

void task3() {
    double arr[10], sum = 0;
    printf("Введіть 10 чисел:\n");
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = ", i);
        scanf("%lf", &arr[i]);
        if (arr[i] > M_E) sum += arr[i];
    }
    printf("Сума елементів більших за e (%.4f): %.4f\n", M_E, sum);
}

void task4() {
    int arr[5], max;
    printf("Введіть 5 цілих чисел:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        if (i == 0) max = arr[i];
        else if (arr[i] > max) max = arr[i];
    }
    printf("Максимальне значення: %d\n", max);
}

void task5() {
    int arr[50], n = 0, even = 0, odd = 0;
    printf("Вводьте числа (0 для зупинки):\n");
    for (int i = 0; i < 50; i++) {
        if (scanf("%d", &arr[i]) != 1 || arr[i] == 0) break;
        if (arr[i] % 2 == 0) even++;
        else odd++;
        n++;
    }
    printf("Парних: %d, Непарних: %d\n", even, odd);
}

void task6() {
    int n;
    double a[20], b[20], res[20];
    printf("Введіть розмірність (n < 20): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 20) return;

    printf("Вектор A:\n"); input_vector(a, n);
    printf("Вектор B:\n"); input_vector(b, n);

    sum_vectors(a, b, res, n);
    printf("Сума A+B: "); print_vector(res, n);
    printf("Скалярний добуток A*B: %.4lf\n", scalar_product(a, b, n));
}

void task7() {
    int arr[20], n = 0, num;
    double product = 1.0, harmonic_sum = 0.0;

    printf("Вводьте ненульові числа (0 для зупинки):\n");
    while (n < 20) {
        if (scanf("%d", &num) != 1 || num == 0) break;
        arr[n] = num;
        product *= num;
        harmonic_sum += 1.0 / num;
        n++;
    }

    if (n > 0) {
        printf("Середнє геометричне: %.4f\n", pow(product, 1.0 / n));
        printf("Середнє гармонічне: %.4f\n", (double)n / harmonic_sum);
    } else {
        printf("Масив порожній.\n");
    }
}

// доп. функції для завдання 6
void input_vector(double vec[], int n) {
    for (int i = 0; i < n; i++) scanf("%lf", &vec[i]);
}

void print_vector(double vec[], int n) {
    printf("(");
    for (int i = 0; i < n; i++) printf("%.2f%s", vec[i], (i < n - 1) ? ", " : "");
    printf(")\n");
}

void sum_vectors(const double v1[], const double v2[], double res[], int n) {
    for (int i = 0; i < n; i++) res[i] = v1[i] + v2[i];
}

double scalar_product(const double v1[], const double v2[], int n) {
    double dot = 0;
    for (int i = 0; i < n; i++) dot += v1[i] * v2[i];
    return dot;
}