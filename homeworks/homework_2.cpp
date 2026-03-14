#include <stdio.h>
#include <math.h>


// Завдання 17: Обчислення th(x) = (e^x - e^-x) / (e^x + e^-x)
double th(double x) {
    double exp_pos = exp(x);
    double exp_neg = exp(-x);
    return (exp_pos - exp_neg) / (exp_pos + exp_neg);
}

// Завдання 17: Похідна th'(x) = 1 - th^2(x)
double th_derivative(double x) {
    double t = th(x);
    return 1.0 - t * t;
}

int main() {
    // ==========================================================
    // 12) Об'єм конуса: V = (1/3) * PI * R^2 * H
    // ==========================================================
    double R, H, V;

    printf("\n--- Завдання 12 ---\n");
    printf("Введіть радіус основи R: ");
    scanf("%lf", &R);
    printf("Введіть висоту конуса H: ");
    scanf("%lf", &H);

    // Обчислення об'єму через бібліотеку math.h
    // M_PI — це стандартна константа числа Пі
    // pow(R, 2) — піднесення радіуса до квадрата
    V = (1.0 / 3.0) * M_PI * pow(R, 2) * H;

    printf("Об'єм конуса V = %.4f\n", V);

    // ==========================================================
    // 17) Виклик власних функцій (th)
    // ==========================================================
    double x_th;
    printf("\n--- Завдання 17 (а) ---\n");
    printf("Введіть x: ");
    scanf("%lf", &x_th);
    printf("f(x) = th(%g) = %.6f\n", x_th, th(x_th));
    printf("g(x) = th'(%g) = %.6f\n", x_th, th_derivative(x_th));
    
    return 0;
    
}