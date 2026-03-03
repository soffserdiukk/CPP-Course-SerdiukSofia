#include <stdio.h>
#include <math.h>

void task13a();
void task23j();

int main() {
    task13a();
    task23j();

    return 0;
}

// Завдання 13-а: Розв'язання системи лінійних рівнянь методом Крамера
void task13a() {
    double a1, b1, c1, a2, b2, c2;
    const double EPS = 1e-9; // Поріг для перевірки на нуль

    printf("Введіть коефіцієнти a1, b1, c1 (a1*x + b1*y + c1 = 0): ");
    scanf("%lf %lf %lf", &a1, &b1, &c1);
    printf("Введіть коефіцієнти a2, b2, c2 (a2*x + b2*y + c2 = 0): ");
    scanf("%lf %lf %lf", &a2, &b2, &c2);

    // Обчислюємо визначники (Система: a*x + b*y = -c)
    double det  = a1 * b2 - a2 * b1;
    double detX = (-c1) * b2 - (-c2) * b1;
    double detY = a1 * (-c2) - a2 * (-c1);


    if (fabs(det) > EPS) {
        // Головний визначник не нуль — один розв'язок
        printf("Результат: x = %g, y = %g\n", detX / det, detY / det);
    } 
    else if (fabs(detX) < EPS && fabs(detY) < EPS) {
        // Усі визначники — нулі
        printf("Результат: Система має безліч розв'язків.\n");
    } 
    else {
        // Головний — нуль, а допоміжні — ні
        printf("Результат: Система не має розв'язків.\n");
    }
}

// Завдання 23-ж: Обчислення нормованої функції sinc(x)
void task23j() {
    double x_val, sinc_res;
    
    printf("Введіть значення x: ");
    scanf("%lf", &x_val); 

    // Обробка усувної особливості в точці 0
    if (fabs(x_val) < 1e-12) {
        sinc_res = 1.0;
    } else {
        sinc_res = sin(x_val) / x_val;
    }
    
    printf("Результат: sinc(%g) = %g\n", x_val, sinc_res);
}
