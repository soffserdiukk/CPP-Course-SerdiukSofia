#include <stdio.h>
#include <string.h>
#include "rational.h"

// --- Оголошення структур ---
typedef struct {
    char name[50];
    int height;
} Mountain;

// --- Прототипи функцій ---
void task4();
void task5();

void input_mountain(Mountain *m);
void print_mountain(Mountain m);
void find_highest(Mountain arr[], int n);
void find_by_name(Mountain arr[], int n, char *search_name);

int main() {
    int choice;
    printf("Виберіть завдання (4 або 5):\n> ");
    if (scanf("%d", &choice) != 1) return 1;

    switch (choice) {
        case 4: task4(); break;
        case 5: task5(); break;
        default: printf("Завдання не знайдено.\n");
    }
    return 0;
}

// --- Реалізація завдань ---

void task4() {
    Rational r1, r2;
    printf("Число 1:\n");
    input_rational(&r1);
    printf("Число 2:\n");
    input_rational(&r2);

    Rational sum = sum_rationals(r1, r2);
    printf("\nСума: "); print_rational(sum);

    Rational prod = mult_rationals(r1, r2);
    printf("\nДобуток: "); print_rational(prod);

    printf("\nРівність: %s\n", compare_rationals(r1, r2) ? "Однакові" : "Різні");
}

void task5() {
    int n;
    printf("Введіть кількість гір: ");
    scanf("%d", &n);

    Mountain mountains[n];
    for (int i = 0; i < n; i++) {
        printf("Гора #%d:\n", i + 1);
        input_mountain(&mountains[i]);
    }

    printf("\n--- Список гір ---\n");
    for (int i = 0; i < n; i++) {
        print_mountain(mountains[i]);
    }

    find_highest(mountains, n);

    char search_name[50];
    printf("\nВведіть назву гори для пошуку її висоти: ");
    scanf("%s", search_name);
    find_by_name(mountains, n, search_name);
}

// --- Допоміжні функції ---

void input_mountain(Mountain *m) {
    printf("  Назва: ");
    scanf("%s", m->name);
    printf("  Висота: ");
    scanf("%d", &m->height);
}

void print_mountain(Mountain m) {
    printf("Гора: %-15s Висота: %d м\n", m.name, m.height);
}

void find_highest(Mountain arr[], int n) {
    if (n <= 0) return;
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].height > arr[max_idx].height) {
            max_idx = i;
        }
    }
    printf("\nНайвища вершина: %s (%d м)\n", arr[max_idx].name, arr[max_idx].height);
}

void find_by_name(Mountain arr[], int n, char *search_name) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, search_name) == 0) {
            printf("Висота гори %s становить %d м.\n", arr[i].name, arr[i].height);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Гору з назвою '%s' не знайдено в базі.\n", search_name);
    }
}