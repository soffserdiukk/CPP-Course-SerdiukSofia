#include <stdio.h>
#include <math.h>

void task1();  void task2();  void task3();  void task4();
void task5();  void task6();  void task7();  void task8();

int main() {
    int task_num;
    printf("Виберіть номер завдання (1-12): ");
    scanf("%d", &task_num);

    switch (task_num) {
        case 1:  task1();  break;
        case 2:  task2();  break;
        case 3:  task3();  break;
        case 4:  task4();  break;
        case 5:  task5();  break;
        case 6:  task6();  break;
        case 7:  task7();  break;
        case 8:  task8();  break;
    }
    return 0;
}

// Завдання 1: Гармонічний ряд
void task1() {
    double a, s = 0.0;
    int n = 0;
    printf("Введіть a: ");
    scanf("%lf", &a);

    while (s <= a) {
        n++;
        s += 1.0 / n;
    }

    printf("а) Перше число > a: %f\n", s);
    printf("б) Найменше n: %d\n", n);
}

// функція для обчислення n-го числа Фібоначчі
long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Завдання 2: Числа Фібоначчі
void task2() {
    int n;
    double a;

    printf("--- Пункт а ---\n");
    printf("Введіть номер члена n: ");
    scanf("%d", &n);
    printf("F(%d) = %ld\n\n", n, fibonacci(n));

    printf("--- Пункти б в г---\n");
    printf("Введіть число a: ");
    scanf("%lf", &a);

    int k = 0;
    long current_fib = 0;

    while (fibonacci(k) <= a) {
        k++;
    }

    // Пункт б
    printf("б) Номер найбільшого числа Фібоначчі <= a: %d\n", k - 1);

    // Пункт в
    printf("в) Номер найменшого числа Фібоначчі > a: %d\n", k);

    long sum = 0;
    int i = 0;
    long f_val;

    // пункт г
    while ((f_val = fibonacci(i)) <= 1000) {
        sum += f_val;
        i++;
    }
    printf("г) Сума чисел Фібоначчі, що не перевищують 1000: %ld\n", sum);
}

// послідовність Коллатца
int collatz_steps(long n, int steps) {
    if (n == 1) {
        return steps;
    }
    if (n % 2 == 0) {
        return collatz_steps(n / 2, steps + 1);
    } else {
        return collatz_steps(3 * n + 1, steps + 1);
    }
}

void task3() {
    int max_steps = 0;
    int best_n = 1;

    printf("Перевірка послідовності для n < 1000...\n");

    for (int n = 1; n < 1000; n++) {
        int current_steps = collatz_steps(n, 0);

        // шук n з макс. кількістю кроків
        if (current_steps > max_steps) {
            max_steps = current_steps;
            best_n = n;
        }
    }

    printf("Результати:\n");
    printf("- Усі числа n < 1000 зійшлися до 1.\n");
    printf("- Число з максимальною кількістю кроків: %d\n", best_n);
    printf("- Кількість кроків для цього числа: %d\n", max_steps);
}

// Рекурсивна функція для факторіала
double factorial(int n) {
    if (n <= 1) return 1.0;
    return n * factorial(n - 1);
}

// Рекурсивна функція для пункту а)
double product_a(int i) {
    if (i == 0) return 1.0; // База: P0 = 1
    double a_i = 1.0 + (1.0 / factorial(i));
    return product_a(i - 1) * a_i;
}

// Рекурсивна функція для пункту б)
double product_b(int i) {
    if (i == 0) return 1.0; // База: P0 = 1
    double term = (pow(-1, i + 1) * pow(i, 2)) / pow(2, i);
    double a_i = 1.0 + term;
    return product_b(i - 1) * a_i;
}

void task4() {
    int n;
    printf("Введіть n для обчислення добутків: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("n має бути натуральним числом!\n");
        return;
    }

    // пункт а
    printf("а) Результат добутку P_n: %lf\n", product_a(n));

    // пункт б
    printf("б) Результат добутку P_n: %lf\n", product_b(n));
}

// обчислення n-го члена послідовності
long sequence_x(int n) {
    // Базові випадки: x1 = x2 = x3 = -99
    if (n == 1 || n == 2 || n == 3) {
        return -99;
    }
    // xn = xn-1 + xn-3 + 100
    return sequence_x(n - 1) + sequence_x(n - 3) + 100;
}

void task5() {
    int n = 1;
    long val;

    printf("Пошук найменшого додатного члена послідовності...\n");

    // Шукаємо перший член, який > 0
    while (1) {
        val = sequence_x(n);
        if (val > 0) {
            break;
        }
        n++;
    }

    printf("Результат:\n");
    printf("- Номер члена (n): %d\n", n);
    printf("- Значення (xn): %ld\n", val);
}

// Рекурсивна функція для обчислення "хвоста" ланцюгового дробу
// n — кількість рівнів, що залишилися
double continued_fraction(double b, int n) {
    // База рекурсії
    if (n == 1) {
        return 1.0 / b;
    }
    // Рекурсивний крок: 1 / (b + наступний рівень)
    return 1.0 / (b + continued_fraction(b, n - 1));
}

void task6() {
    double b;
    int n;

    printf("Введіть число b: ");
    scanf("%lf", &b);
    printf("Введіть глибину дробу n: ");
    scanf("%d", &n);

    if (n <= 0 || b == 0) {
        printf("Помилка: n має бути > 0, а b != 0.\n");
        return;
    }

    double result = b + continued_fraction(b, n);

    printf("Результат ланцюгового дробу b_%d: %lf\n", n, result);
}


double get_b(int k);
double get_a(int k) {
    if (k == 1) return 0.0;
    if (k == 2) return 1.0;
    // a_k = (a_{k-1} / k) + a_{k-2} * b_k
    return (get_a(k - 1) / k) + (get_a(k - 2) * get_b(k));
}

double get_b(int k) {
    if (k == 1) return 1.0;
    if (k == 2) return 0.0;
    // b_k = b_{k-1} + a_{k-1}
    return get_b(k - 1) + get_a(k - 1);
}

double sum_S(int n) {
    if (n == 0) return 0.0;
    double term = pow(2, n) / (get_a(n) + get_b(n));
    return term + sum_S(n - 1);
}

void task7() {
    int n;
    printf("Введіть n для обчислення суми S_n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n має бути більше 0\n");
        return;
    }

    double result = sum_S(n);
    printf("Результат суми S_%d: %lf\n", n, result);
}

// а) Рекурсивне обчислення e^x через ряд Тейлора
// term - поточний доданок, n - номер кроку, eps - точність
double taylor_exp(double x, double term, int n, double eps) {
    if (fabs(term) < eps) return 0;
    // Наступний доданок: x/n * попередній доданок
    double next_term = term * (x / n);
    return term + taylor_exp(x, next_term, n + 1, eps);
}

// б) Рекурсивне обчислення інтеграла Ф(x)
// term - поточний доданок, n - номер кроку (починаючи з 0)
double taylor_phi(double x, double term, int n, double eps) {
    if (fabs(term) < eps) return 0;
    // Рекурентна формула для доданка ряду Ф(x):
    // Наступний = попередній * (-x^2 * (2n+1)) / ((n+1) * (2n+3))
    double multiplier = (-pow(x, 2) * (2 * n + 1)) / ((n + 1) * (2 * n + 3));
    double next_term = term * multiplier;
    return term + taylor_phi(x, next_term, n + 1, eps);
}

void task8() {
    double x, eps;
    printf("Введіть x: ");
    scanf("%lf", &x);
    printf("Введіть точність eps (наприклад, 0.0001): ");
    scanf("%lf", &eps);

    // Обчислення e^x
    double my_exp = taylor_exp(x, 1.0, 1, eps); // 1.0 - перший доданок (x^0/0!)
    double std_exp = exp(x);

    printf("\n--- Результати для e^x ---\n");
    printf("Ряд Тейлора: %lf\n", my_exp);
    printf("Стандартна exp(): %lf\n", std_exp);
    printf("Різниця: %e\n", fabs(my_exp - std_exp));

    // Обчислення Ф(x)
    // Перший доданок ряду для Ф(x) це x (при n=0)
    double my_phi = taylor_phi(x, x, 0, eps);

    printf("\n--- Результати для Ф(x) ---\n");
    printf("Ряд Тейлора: %lf\n", my_phi);
    printf("Примітка: Ф(x) порівнюється з результатом ряду.\n");
}


// а) v0 = 1, v1 = 0.3, vi = (i + 2) * vi-2
double seq_9a(int i) {
    if (i == 0) return 1.0;
    if (i == 1) return 0.3;
    return (i + 2) * seq_9a(i - 2);
}

// б) v0 = v1 = v2 = 1, vi = (i + 4)(vi-1 - 1) + (i + 5)vi-3
double seq_9b(int i) {
    if (i == 0 || i == 1 || i == 2) return 1.0;
    return (i + 4) * (seq_9b(i - 1) - 1.0) + (i + 5) * seq_9b(i - 3);
}

// в) v0 = v1 = 0, v2 = 1.5, vi = формула з дробом
double seq_9v(int i) {
    if (i == 0 || i == 1) return 0.0;
    if (i == 2) return 1.5;
    // (i-2) / ((i-3)^2 + 1) * vi-1 - vi-2 * vi-3 + 1
    double fraction = (double)(i - 2) / (pow(i - 3, 2) + 1);
    return fraction * seq_9v(i - 1) - seq_9v(i - 2) * seq_9v(i - 3) + 1.0;
}

