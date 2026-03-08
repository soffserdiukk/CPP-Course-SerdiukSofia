#include <stdio.h>
#include <math.h>

// --- Прототипи рекурсивних функцій ---
long reverse_number(long n, long current_rev);
double taylor_cos(double x, double term, int n, double eps);

// --- Оголошення функцій завдань ---
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

// --- Реалізація завдань ---

// Завдання 15: Інверсія числа
void task15() {
    long n;
    printf("\n--- Завдання 15: Інверсія числа ---\n");
    printf("Введіть число n: ");
    scanf("%ld", &n);

    // Виклик рекурсивної функції
    long result = (n == 0) ? 0 : reverse_number(n, 0);
    printf("Число у зворотному порядку: %ld\n", result);
}

// Завдання 16: Ряд Тейлора для cos(x)
void task16() {
    double x, eps;
    printf("\n--- Завдання 16: cos(x) через ряд Тейлора ---\n");
    printf("Введіть x (в радіанах): ");
    scanf("%lf", &x);
    printf("Введіть точність eps: ");
    scanf("%lf", &eps);

    // Перший доданок cos(x) це 1.0 (при n=0)
    double my_cos = taylor_cos(x, 1.0, 1, eps);
    printf("Результат: %.10f\n", my_cos);
    printf("Стандартний cos(x): %.10f\n", cos(x));
}

// --- Допоміжні рекурсивні функції ---

// Рекурсивна інверсія (використовує вказівку y_i = y_{i-1} * 10 + a_i)
long reverse_number(long n, long current_rev) {
    if (n == 0) {
        return current_rev;
    }
    // n % 10 - це остання цифра (a_i)
    return reverse_number(n / 10, current_rev * 10 + (n % 10));
}

// Рекурсивний косинус
double taylor_cos(double x, double term, int n, double eps) {
    if (fabs(term) < eps) {
        return 0;
    }
    // Рекурентне співвідношення для наступного доданка
    double multiplier = -(x * x) / ((2 * n - 1) * (2 * n));
    return term + taylor_cos(x, term * multiplier, n + 1, eps);
}