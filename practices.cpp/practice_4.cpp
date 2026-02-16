#include <stdio.h>
#include <math.h>
#include <float.h>

// --- ПРОТОТИПИ ФУНКЦІЙ ---
void task1(); 
void task2(); 
void task3(); 
void task4(); 
void task5();
void task6(); 
void task7(); 
void task8(); 
void task9(); 
void task10(); 
void task11();

int main() {
    int task_num;
    printf("Виберіть номер завдання (1-11): ");
    scanf("%d", &task_num);

    if (task_num == 1) {
        printf("Завдання 1: Вкладені синуси sin(sin(...))\n");
        task1();
    } 
    else if (task_num == 2) {
        printf("Завдання 2: Факторіал як рядок множників\n");
        task2();
    } 
    else if (task_num == 3) {
        printf("Завдання 3: Обчислення многочленів (а, б)\n");
        task3();
    } 
    else if (task_num == 4) {
        printf("Завдання 4: Сума ряду i * x^i\n");
        task4();
    } 
    else if (task_num == 5) {
        printf("Завдання 5: Подвійний факторіал n!!\n");
        task5();
    } 
    else if (task_num == 6) {
        printf("Завдання 6: Вкладені корені (а, б)\n");
        task6();
    } 
    else if (task_num == 7) {
        printf("Завдання 7: Многочлен (експонента) через x^n/n!\n");
        task7();
    } 
    else if (task_num == 8) {
        printf("Завдання 8: Найбільше k, при якому 4^k <= m\n");
        task8();
    } 
    else if (task_num == 9) {
        printf("Завдання 9: Найменше 2^r > n\n");
        task9();
    } 
    else if (task_num == 10) {
        printf("Завдання 10: Пошук машинного нуля\n");
        task10();
    } 
    else if (task_num == 11) {
        printf("Завдання 11: Послідовність\n");
        task11();
    } 
    else {
        printf("Невірний номер завдання.\n");
    }

    return 0;
}

// --- РЕАЛІЗАЦІЯ ЗАВДАНЬ ---

void task1() {
    double x, y; int n;
    printf("Введіть x та n: ");
    scanf("%lf %d", &x, &n);
    y = x;

    for (int i = 0; i < n; i++) 
    y = sin(y);

    printf("Результат: %f\n", y);
}

void task2() {
    unsigned n;
    printf("Введіть n: "); 
    scanf("%u", &n);

    // 1. Цикл по діапазону із зростанням
    printf("%u! = ", n);
    for (unsigned i = 1; i <= n; i++) {
        printf("%u%s", i, (i == n ? "" : "*"));
    }
    printf("\n");

    // 2. Цикл по діапазону зі спаданням
    printf("%u! = ", n);
    for (unsigned i = n; i >= 1; i--) {
        printf("%u%s", i, (i == 1 ? "" : "*"));
    }
    printf("\n");
}

void task3() {
    double x_a = 2, y_a = 0; 
    int n_a = 3;
    for (int i = 0; i <= n_a; i++) y_a += pow(x_a, i);
    printf("а) n=3, x=2: %g\n", y_a);

    double x_b = 1, y_b = 2, res_b = 0; 
    int n_b = 4;

    for (int i = 0; i <= n_b; i++) 
    res_b += pow(x_b * x_b * y_b, i);
    
    printf("б) n=4, x=1, y=2: %g\n", res_b);
}

void task4() {
    int n; 
    double x, sum = 0;
    printf("Введіть n та x: ");
    scanf("%d %lf", &n, &x);

    for (int i = 1; i <= n; i++) 
         sum += i * pow(x, i);
    printf("Результат: %f\n", sum);
}

void task5() {
    unsigned n; 
    unsigned long long res = 1;
    printf("Введіть n: "); 
    scanf("%u", &n);

    for (int i = n; i >= 1; i -= 2) 
          res *= i;
    printf("%u!! = %llu\n", n, res);
}

void task6() {
    int n; 

    printf("Введіть n: "); 
    scanf("%d", &n);

    double res_a = 0, res_b = 0;

    for (int i = 0; i < n; i++) 
         res_a = sqrt(2 + res_a);

    for (int i = n; i >= 1; i--) 
         res_b = sqrt(3 * i + res_b);

    printf("а) %f\nб) %f\n", res_a, res_b);
}

void task7() {
    int n; 
    double x, sum = 1, term = 1;

    printf("Введіть n та x: ");
    scanf("%d %lf", &n, &x);

    for (int i = 1; i <= n; i++) {
        term *= x / i;
        sum += term;
    }
    printf("Результат: %f\n", sum);
}

void task8() {
    int m, k = 0; 
    long long val = 1;

    printf("Введіть m: "); 
    scanf("%d", &m);

   while (val * 4 <= m) 
      val *= 4; 
      k++; 
    printf("Найбільше k = %d (4^%d <= %d)\n", k, k, m);
}

void task9() {
    int n; 
    long long res = 1;

    printf("Введіть n: "); 
    scanf("%d", &n);

    while (res <= n) 
         res *= 2;
    printf("Результат: %lld\n", res);
}

void task10() {
    float a = 1.0f;
    while (1.0f + a / 2.0f != 1.0f) 
           a /= 2.0f;

    printf("Машинний нуль для float: %e\n", a);
}

void task11() {
    double val, sum = 0, prod = 1; 
    int count = 0;

    while (1) {
        printf("a[%d] (нуль для виходу)= ", count);
        scanf("%lf", &val);

        if (fabs(val) < 1e-15) 
             break; 

        sum += val; 
        prod *= val; 
        count++;
    }

    if (count > 0) {
        printf("\nСума: %f\nСер. арифметичне: %f\nСер. геометричне: %f\n", 
                sum, sum / count, pow(prod, 1.0 / count));
    }
}
