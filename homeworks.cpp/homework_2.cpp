#include <stdio.h>
#include <math.h>

double th(double x);
double th_derivative(double x);

int main() {
    // --- Завдання 12: Об'єм конуса ---
    double R, H, V;

    printf("=== РЕЗУЛЬТАТИ ЗАВДАННЯ 12 ===\n");
    printf("Введіть радіус основи R: ");
    scanf("%lf", &R);
    printf("Введіть висоту конуса H: ");
    scanf("%lf", &H);

    // V = (1/3) * PI * R^2 * H
    V = (1.0 / 3.0) * M_PI * pow(R, 2) * H;
    printf("Об'єм конуса V = %.4f\n", V);

    // --- Завдання 17: Гіперболічний тангенс та його похідна ---
    double x_th;
    printf("\n=== РЕЗУЛЬТАТИ ЗАВДАННЯ 17 ===\n");
    printf("Введіть значення x: ");
    scanf("%lf", &x_th);

    printf("f(x) = th(%g) = %.6f\n", x_th, th(x_th));
    printf("g(x) = th'(%g) = %.6f\n", x_th, th_derivative(x_th));

    return 0;
}

// th(x) = (e^x - e^-x) / (e^x + e^-x)
double th(double x) {
    double exp_pos = exp(x);
    double exp_neg = exp(-x);
    return (exp_pos - exp_neg) / (exp_pos + exp_neg);
}

// Похідна th'(x) = 1 - th^2(x)
double th_derivative(double x) {
    double t = th(x);
    return 1.0 - t * t;
}

