#include <stdio.h>
#include <math.h>

int main() {
    // --- ЗАВДАННЯ 1: Арифметичні вирази ---
    int a = 2, b = 31, c = 45, d = 54, e = 11;
    int f = 15, g = 4, h = 67, i = 5;
    double f_d = 15.0, g_d = 4.0;
    double v1 = 2.0, v2 = 45.1, v3 = 3.2, v4 = 2.0;

    printf("=== РЕЗУЛЬТАТИ ЗАВДАННЯ 1 ===\n");
    printf("1) Додавання: %d + %d = %d\n", a, b, a + b);
    printf("2) Множення та віднімання: %d * %d - %d = %d\n", c, d, e, c * d - e);
    printf("3) Цілочисельне ділення: %d / %d = %d\n", f, g, f / g);
    printf("4) Дійсне ділення: %.1f / %.1f = %.2f\n", f_d, g_d, f_d / g_d);
    printf("5) Остача від ділення: %d %% %d = %d\n", h, i, h % i);
    printf("6) Складний вираз: (%.1f * %.1f + %.1f) / %.1f = %.2f\n", v1, v2, v3, v4, (v1 * v2 + v3) / v4);

    // --- ЗАВДАННЯ 2: Математичні константи ---
    printf("\n=== РЕЗУЛЬТАТИ ЗАВДАННЯ 2 ===\n");
    printf("1) 10^-4   = %.4f\n", 1e-4);
    printf("2) 24.33E5 = %.2f\n", 24.33e5);
    printf("3) Число Пі = %.4f\n", M_PI);
    printf("4) Число е  = %.4f\n", M_E);
    printf("5) Корінь з 5 = %.4f\n", sqrt(5.0));
    printf("6) ln(100)  = %.4f\n", log(100.0));

    // --- ЗАВДАННЯ 3: Форматований вивід ---
    int user_num;
    printf("\n=== ЗАВДАННЯ 3 ===\nВведіть ціле число: ");
    scanf("%d", &user_num);
    printf("Форматована таблиця з числом %d:\n", user_num);
    printf("%d)\n\n", user_num);
    printf("- %d - %d - %d\n\n", user_num, user_num, user_num);
    printf(" %d | %d | %d\n\n", user_num, user_num, user_num);
    printf("- %d - %d - %d\n", user_num, user_num, user_num);

    // --- ЗАВДАННЯ 4: Сила притягання ---
    const double G = 6.674e-11;
    double m1, m2, r, force;
    printf("\n=== ЗАВДАННЯ 4 ===\nВведіть масу m1, m2 (кг) та відстань r (м): ");
    scanf("%lf %lf %lf", &m1, &m2, &r);
    force = G * (m1 * m2) / (r * r);
    printf("Сила притягання F = %e Н\n", force);

    // --- ЗАВДАННЯ 5: Оптимізація степенів ---
    double x, res_p2, res_p3, res_p4;
    printf("\n=== ЗАВДАННЯ 5 ===\nВведіть число x: ");
    scanf("%lf", &x);

    res_p2 = x * x;
    res_p4 = res_p2 * res_p2;
    printf("x^4  = %.2f\n", res_p4);

    res_p3 = res_p2 * x;
    printf("x^6  = %.2f\n", res_p3 * res_p3);
    printf("x^9  = %.2f\n", res_p4 * res_p4 * x);
    printf("x^15 = %.2f\n", res_p3 * res_p3 * res_p3 * res_p3 * res_p3);
    
    double res_p7 = res_p4 * res_p3;
    double res_p14 = res_p7 * res_p7;
    printf("x^28 = %.2f\n", res_p14 * res_p14);
    
    double res_p8 = res_p4 * res_p4;
    double res_p16 = res_p8 * res_p8;
    double res_p32 = res_p16 * res_p16;
    printf("x^64 = %.2f\n", res_p32 * res_p32);

    // --- ЗАВДАННЯ 6: Конвертація температури ---
    double celsius;
    printf("\n=== ЗАВДАННЯ 6 ===\nВведіть температуру в градусах Цельсія: ");
    scanf("%lf", &celsius);
    printf("За Фаренгейтом: %g F\n", (9.0 * celsius / 5.0) + 32);

    // --- ЗАВДАННЯ 7: Обробка дійсного числа ---
    double val;
    printf("\n=== ЗАВДАННЯ 7 ===\nВведіть дійсне число: ");
    scanf("%lf", &val);
    printf("Ціла частина (trunc): %.0f\n", trunc(val));
    printf("Дробова частина (fmod): %f\n", fmod(val, 1.0));
    printf("Округлення: ceil=%.0f, floor=%.0f, round=%.0f\n", ceil(val), floor(val), round(val));

    // --- ЗАВДАННЯ 8: Операції з двома числами ---
    double n_a, n_b;
    printf("\n=== ЗАВДАННЯ 8 ===\nВведіть два числа через пробіл: ");
    scanf("%lf %lf", &n_a, &n_b);
    printf("Різниця: %.2f\n", n_a - n_b);
    printf("Добуток: %.2f\n", n_a * n_b);

    // --- ЗАВДАННЯ 9: Середні значення ---
    double num1, num2;
    printf("\n=== ЗАВДАННЯ 9 ===\nВведіть два числа для розрахунку середніх: ");
    scanf("%lf %lf", &num1, &num2);
    double s_arith = (num1 + num2) / 2.0;
    double s_harm = (2.0 * num1 * num2) / (num1 + num2);
    printf("Середнє арифметичне: %.4f (науковий: %e)\n", s_arith, s_arith);
    printf("Середнє гармонічне:   %.4f (науковий: %e)\n", s_harm, s_harm);

    return 0;
}