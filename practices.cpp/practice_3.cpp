#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

// Прототипи функцій-завдань
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();

int main() {
    int task_num;
    printf("Виберіть номер завдання (1-7): ");
    scanf("%d", &task_num);

    if (task_num == 1) {
        printf("Завдання 1: Розклад тризначного числа\n");
        task1();
    } else if (task_num == 2) {
        printf("Завдання 2: Перестановки цифр\n");
        task2();
    } else if (task_num == 3) {
        printf("Завдання 3: Добуток чисел\n");
        task3();
    } else if (task_num == 4) {
        printf("Завдання 4: Множення 8-бітних чисел\n");
        task4();
    } else if (task_num == 5) {
        printf("Завдання 5: Порівняння двох чисел\n");
        task5();
    } else if (task_num == 6) {
        printf("Завдання 6: Пошук екстремумів за модулем\n");
        task6();
    } else if (task_num == 7) {
        printf("Завдання 7: Розв'язання квадратного рівняння\n");
        task7();
    } else {
        printf("\nПомилка: Невірний номер завдання.\n");
    }

    return 0;
}

void task1() {
    int n1;
    printf("Введіть число: ");
    scanf("%d", &n1);
    int h = n1 / 100, t = (n1 / 10) % 10, u = n1 % 10;
    printf("Сотень: %d, Десятків: %d, Одиниць: %d\n", h, t, u);
    printf("Сума цифр: %d, Навпаки: %d%d%d\n", h + t + u, u, t, h);
}

void task2() {
    int n2;
    printf("Введіть тризначне число: ");
    scanf("%d", &n2);
    int d1 = n2 / 100, d2 = (n2 / 10) % 10, d3 = n2 % 10;
    if (d1 != d2 && d1 != d3 && d2 != d3) {
        printf("Перестановки: %d%d%d, %d%d%d, %d%d%d, %d%d%d, %d%d%d, %d%d%d\n", 
                d1,d2,d3, d1,d3,d2, d2,d1,d3, d2,d3,d1, d3,d1,d2, d3,d2,d1);
    } else printf("Є однакові цифри.\n");
}

void task3() {
    long long a, b, c;
    printf("Введіть три числа через кому: ");
    scanf("%lld,%lld,%lld", &a, &b, &c);
    if (llabs(a) < 1024 && llabs(b) < 1024 && llabs(c) < 1024)
        printf("Добуток (int): %d\n", (int)(a * b * c));
    else
        printf("Добуток (long long): %lld\n", a * b * c);
}

void task4() {
    unsigned int arg1, arg2;
    printf("Введіть два числа (0-255): ");
    scanf("%u %u", &arg1, &arg2);

    uint8_t num1 = (uint8_t)arg1;
    uint8_t num2 = (uint8_t)arg2;
    uint16_t result = (uint16_t)num1 * num2;

    printf("Результат множення (uint16_t): %u\n", result);
}

void task5() {
    double x, y;
    printf("Введіть x та y: ");
    scanf("%lf %lf", &x, &y);
    if (x > y) printf("Більше: %g, Менше: %g\n", x, y);
    else if (y > x) printf("Більше: %g, Менше: %g\n", y, x);
    else printf("Числа рівні\n");
}

void task6() {
    double a, b, c;
    printf("Введіть три числа: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double mx = a, mn = a;
    if (fabs(b) > fabs(mx)) mx = b; if (fabs(c) > fabs(mx)) mx = c;
    if (fabs(b) < fabs(mn)) mn = b; if (fabs(c) < fabs(mn)) mn = c;
    printf("Макс за модулем: %g, Мін за модулем: %g\n", mx, mn);
}

void task7() {
    double a, b, c;
    printf("Введіть a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double D = b * b - 4 * a * c;
    if (D >= 0) {
        printf("Корені: %g, %g\n", (-b + sqrt(D))/(2*a), (-b - sqrt(D))/(2*a));
    } else {
        printf("Дійсних коренів немає.\n");
    }
}

