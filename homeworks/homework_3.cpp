#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {

    // ==========================================================
    // 13-а) Система лінійних рівнянь (Метод Крамера)
    // ==========================================================
    double a1, b1, c1_const, a2, b2, c2_const;
    printf("\n--- Завдання 13-а (Система лінійних рівнянь) ---\n");
    printf("Введіть коефіцієнти a1, b1, c1 (для a1*x + b1*y + c1 = 0): ");
    scanf("%lf %lf %lf", &a1, &b1, &c1_const);
    printf("Введіть коефіцієнти a2, b2, c2 (для a2*x + b2*y + c2 = 0): ");
    scanf("%lf %lf %lf", &a2, &b2, &c2_const);

    // ел. стовбчика вільних членів
    double free1 = -c1_const;
    double free2 = -c2_const;

    // Головний визначник матриці
    double det = a1 * b2 - a2 * b1;

    if (det != 0) {
        // Один розв'язок
        double dx = free1 * b2 - free2 * b1;
        double dy = a1 * free2 - a2 * free1;
        printf("Система має 1 розв'язок: x = %g, y = %g\n", dx / det, dy / det);
    } 
    else {
        // Якщо головний визначник нуль, перевіряємо допоміжні
        double dx = free1 * b2 - free2 * b1;
        double dy = a1 * free2 - a2 * free1;

        if (dx == 0 && dy == 0) {
            printf("Система має безліч розв'язків.\n");
        } else {
            printf("Система не має розв'язків.\n");
        }
    }

    // ==========================================================
    // 23-ж) Функція sinc(x)
    // ==========================================================
    double x_val, sinc_res;
    printf("\n--- Завдання 23- ж (sinc) ---\n");
    printf("Введіть x: ");
    scanf("%lf", &x_val);

    if (x_val == 0) {
        sinc_res = 1;
    } else {
        sinc_res = sin(x_val) / x_val;
    }
    printf("sinc(%g) = %g\n", x_val, sinc_res);

    return 0;
}