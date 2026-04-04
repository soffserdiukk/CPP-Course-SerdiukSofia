#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Оголошення структур ---

// Завдання 10.6 (і):
typedef struct {
    int size;
    double *values;
} Vector;

// Завдання 10.9: Предмет (маса та об'єм)
typedef struct {
    char name[50];
    double mass;
    double volume;
} Item;

// --- Прототипи функцій ---
void task1();
void task2();


void input_vector(Vector *v);
void print_vector(Vector v);
void free_vector(Vector *v);


void input_item(Item *it);
void find_max_density(Item arr[], int n);

// --- Головна функція ---
int main() {
    int choice;
    printf("Виберіть завдання домашньої роботи (1 або 2):\n");

    if (scanf("%d", &choice) != 1) return 1;

    switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        default: printf("Невірний вибір.\n");
    }
    return 0;
}

// --- Реалізація завдань ---

void task1() {
    Vector v;
    input_vector(&v);
    print_vector(v);
    free_vector(&v); // Не забуваємо чистити пам'ять
}

void task2() {
    int n;
    printf("Введіть кількість предметів (N): ");
    scanf("%d", &n);

    if (n <= 0) return;

    Item *items = (Item*)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        printf("Предмет #%d:\n", i + 1);
        input_item(&items[i]);
    }

    find_max_density(items, n);

    free(items);
}

// --- Допоміжні функції ---

// Завдання 1: Вектор
void input_vector(Vector *v) {
    printf("Введіть розмір вектора: ");
    scanf("%d", &v->size);

    if (v->size <= 0) {
        v->values = NULL;
        return;
    }

    v->values = (double*)malloc(v->size * sizeof(double));
    printf("Введіть %d елементів вектора:\n", v->size);
    for (int i = 0; i < v->size; i++) {
        printf("  [%d] = ", i);
        scanf("%lf", &v->values[i]);
    }
}

void print_vector(Vector v) {
    if (v.size <= 0 || v.values == NULL) {
        printf("Вектор порожній.\n");
        return;
    }
    printf("Вектор: (");
    for (int i = 0; i < v.size; i++) {
        printf("%.2lf%s", v.values[i], (i == v.size - 1) ? "" : ", ");
    }
    printf(")\n");
}

void free_vector(Vector *v) {
    free(v->values);
    v->values = NULL;
    v->size = 0;
}

// Завдання 2: Предмети та густина
void input_item(Item *it) {
    printf("  Назва предмета: ");
    scanf("%s", it->name);
    printf("  Маса (кг): ");
    scanf("%lf", &it->mass);
    printf("  Об'єм (м3): ");
    scanf("%lf", &it->volume);
}

void find_max_density(Item arr[], int n) {
    int max_idx = 0;
    double max_density = -1.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].volume > 0) {
            // Формула густини: p = m / V
            double current_density = arr[i].mass / arr[i].volume;
            if (current_density > max_density) {
                max_density = current_density;
                max_idx = i;
            }
        }
    }

    if (max_density >= 0) {
        printf("\nНайбільшу густину має матеріал предмета: %s\n", arr[max_idx].name);
        printf("Густина: %.2lf кг/м3\n", max_density);
    } else {
        printf("\nДані для обчислення густини некоректні.\n");
    }
}