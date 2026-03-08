#include <stdio.h>
#include <math.h>

// Прототипи допоміжних рекурсивних функцій
long reverse_number(long n, long current_rev);
double taylor_cos(double x, double term, int n, double eps);

// Оголошення функцій завдань
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

// Завдання 15: Інверсія числа (запис у зворотному порядку)
void task15() {
    long n;
    printf("\n--- Завдання 15: Інверсія ---\nВведіть натуральне число n: ");
    scanf("%ld", &n);

    // Згідно з вказівкою: y_i = y_{i-1} * 10 + a_i
    long inverted = (n == 0) ? 0 : reverse_number(n, 0);
    printf("Результат інверсії: %ld\n", inverted);
}

// Завдання 16б: Наближене обчислення cos(x)
void task16() {
    double x, eps;
    printf("\n--- Завдання 16б: cos(x) ---\nВведіть x (рад) та точність eps: ");
    scanf("%lf %lf", &x, &eps);

    // Перший доданок cos(x) це 1.0 (при n=0)
    double result = taylor_cos(x, 1.0, 1, eps);
    printf("Обчислений cos(x): %.10f\n", result);
    printf("Стандартний cos(x): %.10f\n", cos(x));
}

// РЕКУРСИВНІ ФУНКЦІЇ

long reverse_number(long n, long current_rev) {
    if (n == 0) return current_rev;
    // Беремо останню цифру (n % 10) і додаємо до результату
    return reverse_number(n / 10, current_rev * 10 + (n % 10));
}

double taylor_cos(double x, double term, int n, double eps) {
    if (fabs(term) < eps) return 0;
    // Рекурентне співвідношення для доданка cos(x)
    double mult = -(x * x) / ((2 * n - 1) * (2 * n));
    return term + taylor_cos(x, term * mult, n + 1, eps);
}