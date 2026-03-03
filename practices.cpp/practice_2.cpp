#include <stdio.h>
#include <math.h>

int main() {
    // --- Завдання 1: Тригонометричний косинус ---
    double x, res_cos;
    printf("=== РЕЗУЛЬТАТИ ЗАВДАННЯ 1 ===\n");
    printf("Введіть число x: ");
    scanf("%lf", &x);

    res_cos = cos(x);
    printf("cos(%g) = %.4f\n", x, res_cos);

    // --- Завдання 2: Гіпотенуза прямокутного трикутника ---
    double a, b, c;
    printf("\n=== РЕЗУЛЬТАТИ ЗАВДАННЯ 2 ===\n");
    printf("Введіть катети a та b: ");
    scanf("%lf %lf", &a, &b);

    c = sqrt(a * a + b * b);
    printf("Гіпотенуза c = %.2f\n", c);

    // --- Завдання 3: Площа трикутника за формулою Герона ---
    double s1, s2, s3, p, S;
    printf("\n=== РЕЗУЛЬТАТИ ЗАВДАННЯ 3 ===\n");
    printf("Введіть сторони трикутника s1, s2, s3: ");
    scanf("%lf %lf %lf", &s1, &s2, &s3);

    p = (s1 + s2 + s3) / 2.0;
    S = sqrt(p * (p - s1) * (p - s2) * (p - s3));
    printf("Площа S = %.2f\n", S);

    // --- Завдання 4: Многочлен ---
    double x1, x2, y;
    printf("\n=== РЕЗУЛЬТАТИ ЗАВДАННЯ 4 ===\n");
    printf("Введіть x: ");
    scanf("%lf", &x1);

    // Схема Горнера
    x2 = x1 * x1;
    y = x1 * (x2 * (x2 + 1) + 1);
    printf("y = %.2f\n", y);

    // --- Завдання 5: Функція Розенброка ---
    double x_r, y_r, res_r;
    printf("\n=== РЕЗУЛЬТАТИ ЗАВДАННЯ 5 ===\n");
    printf("Введіть x та y: ");
    scanf("%lf %lf", &x_r, &y_r);

    res_r = 100.0 * pow((x_r * x_r - y_r), 2) + pow((x_r - 1.0), 2);
    printf("Rosenbrock2d(%g, %g) = %.4f\n", x_r, y_r, res_r);

    // --- Завдання 6: Площа за координатами вершин ---
    double xA, yA, xB, yB, xC, yC;
    double sideAB, sideBC, sideAC, p_coord, S_coord;

    printf("\n=== РЕЗУЛЬТАТИ ЗАВДАННЯ 6 ===\n");
    printf("Введіть координати точки А (x y): ");
    scanf("%lf %lf", &xA, &yA);
    printf("Введіть координати точки B (x y): ");
    scanf("%lf %lf", &xB, &yB);
    printf("Введіть координати точки C (x y): ");
    scanf("%lf %lf", &xC, &yC);

    // Розрахунок довжин сторін
    sideAB = sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));
    sideBC = sqrt(pow(xC - xB, 2) + pow(yC - yB, 2));
    sideAC = sqrt(pow(xC - xA, 2) + pow(yC - yA, 2));

    // Розрахунок площі
    p_coord = (sideAB + sideBC + sideAC) / 2.0;
    S_coord = sqrt(p_coord * (p_coord - sideAB) * (p_coord - sideBC) * (p_coord - sideAC));

    printf("\nДовжини сторін: AB=%.2f, BC=%.2f, AC=%.2f\n", sideAB, sideBC, sideAC);
    printf("Площа трикутника S = %.4f\n", S_coord);

    return 0;
}

