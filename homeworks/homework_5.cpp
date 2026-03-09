#include <stdio.h>
#include <math.h>

long reverse_number(long n, long current_rev);
double calculate_sum_recursive(int k, double ak, double x, double eps);

void task15();
void task16();

int main() {
    int task_num;
    printf("Виберіть номер завдання (15 або 16): ");
    if (scanf("%d", &task_num) != 1) return 1;

    switch (task_num) {
        case 15: task15(); break;
        case 16: task16(); break;
        default: printf("Завдання не знайдено.\n");
    }
    return 0;
}

// Завдання 15: Інверсія числа
void task15() {
    long n;
    printf("\n--- Завдання 15: Інверсія ---\nВведіть число n: ");
    if (scanf("%ld", &n) != 1) return;

    long inverted = reverse_number(n, 0);
    printf("Результат інверсії: %ld\n", inverted);
}

// Завдання 16(i): Обчислення ряду
void task16() {
    double x = 0.5;
    double eps;

    printf("Введіть точність eps (наприклад, 0.00001): ");
    if (scanf("%lf", &eps) != 1) return;

    // k=0, a0=1.0 згідно з формулою розкладу
    double y = calculate_sum_recursive(0, 1.0, x, eps);

    printf("Результат y:         %.10f\n", y);
    printf("Перевірка формулою:  %.10f\n", 1.0 / pow(1.0 + x, 3));
}

// Реалізація інверсії
long reverse_number(long n, long current_rev) {
    if (n == 0) return current_rev;
    return reverse_number(n / 10, current_rev * 10 + (n % 10));
}

// Реалізація обчислення суми
double calculate_sum_recursive(int k, double ak, double x, double eps) {
    // Умова виходу за точністю |ak| >= eps
    if (fabs(ak) < eps) {
        return 0;
    }

    double next_ak = ak * (-x) * (double)(k + 3) / (k + 1);

    // Sk = Sk-1 + ak
    return ak + calculate_sum_recursive(k + 1, next_ak, x, eps);
}