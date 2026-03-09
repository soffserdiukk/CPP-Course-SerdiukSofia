#include <stdio.h>

void task8();
void task10();
bool is_fibonacci(int n);

int main() {
    int task_num;
    printf("Виберіть номер завдання (8 або 10): ");
    if (scanf("%d", &task_num) != 1) return 1;

    switch (task_num) {
        case 8:  task8();  break;
        case 10:  task10();  break;
        default: printf("Завдання не знайдено.\n");
    }
    return 0;
}

// Перевірка, чи є число числом Фібоначчі
bool is_fibonacci(int n) {
    if (n < 0) return false;
    if (n == 0 || n == 1) return true;

    int a = 0, b = 1;
    int next = a + b;

    while (next < n) {
        a = b;
        b = next;
        next = a + b;
    }
    return (next == n);
}

// Визначити скільки в масиві чисел Фібоначчі
void task8() {
    int n, count = 0;
    printf("\n--- Завдання 8г: Числа Фібоначчі ---\n");
    printf("Введіть розмір масиву N: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введіть %d натуральних чисел:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
        if (is_fibonacci(arr[i])) {
            count++;
        }
    }
    printf("Результат: у масиві %d чисел Фібоначчі.\n", count);
}

// Визначити мінімальний елемент серед тих, що мають парні індекси
void task10() {
    int n;
    printf("Введіть розмір масиву N: ");
    scanf("%d", &n);

    if (n <= 0) return;

    int arr[n];
    printf("Введіть %d елементів:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    for (int i = 0; i < n; i += 2) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Мінімальний елемент на парних позиціях: %d\n", min);
}