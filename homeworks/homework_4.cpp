#include <stdio.h>
#include <math.h>


int main() {
    // --- ЗАВДАННЯ 13 (д) ---
    printf("--- Task 13 (d) ---\n");

    double x, y13 = 0.0;
    int n;

    printf("Enter x (0 < x < 1): ");
    scanf("%lf", &x);
    printf("Enter n (n >= 0): ");
    scanf("%d", &n);

    for (int k = 0; k <= n; k++) {
        y13 += k * pow(x, k) * pow(1.0 - x, n - k);
    }

    printf("Result y = %.10f\n\n", y13);


    // --- ЗАВДАННЯ 27 (в) ---
    printf("--- Task 27 (v) ---\n");

    double eps;
    printf("Enter precision epsilon (e.g., 0.00001): ");
    scanf("%lf", &eps);

    double product = 1.0;
    double current_sqrt = 0.0; 
    double pi_approx = 0.0;
    double prev_pi = 0.0;
    int first_iteration = 1;

    do {
        prev_pi = pi_approx;
        
        current_sqrt = sqrt(2.0 + current_sqrt);
        
        product *= (current_sqrt / 2.0);
        
        pi_approx = 2.0 / product;

        if (first_iteration) {
            first_iteration = 0;
            continue; // На першому кроці різницю ще не рахуємо
        }

    } while (fabs(pi_approx - prev_pi) >= eps);

    printf("Calculated PI = %.10f\n", pi_approx);
    printf("Reference PI  = %.10f\n", M_PI);

    return 0;
}