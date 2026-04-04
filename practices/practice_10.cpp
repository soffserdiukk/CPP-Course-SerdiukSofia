#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// --- Оголошення структур ---
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char col;
    int row;
} ChessField;

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Rectangle;

typedef struct {
    int degree;
    double *coeffs;
} Polynomial;



// --- Прототипи функцій ---
void task1a();
void task1b();
void task1c();
void task1d();
void task2();
void task3();


void input_date(Date *d);
void print_date(Date d);

void input_field(ChessField *f);
void print_field(ChessField f);

void input_point(Point *p, const char *label);
void input_rectangle(Rectangle *r);
void print_rectangle(Rectangle r);

void input_polynomial(Polynomial *p);
void print_polynomial(Polynomial p);
void free_polynomial(Polynomial *p);

bool can_queen_move(ChessField s, ChessField t);

bool is_leap(int y);
int days_in_month(int m, int y);
Date get_tomorrow(Date d);
const char* get_day_of_week(Date d);



// --- Головна функція ---
int main() {
    int task_num;
    printf("Виберіть номер завдання (): ");
    if (scanf("%d", &task_num) != 1) return 1;

    switch (task_num) {
        case 1: task1a(); break;
        case 2: task1b(); break;
        case 3: task1c(); break;
        case 4: task1d(); break;
        case 5: task2(); break;
        case 6: task3(); break;

        default: printf("Завдання не знайдено.\n");
    }
    return 0;
}

// --- Реалізація завдань ---

void task1a() {
    Date my_date;
    input_date(&my_date);
    print_date(my_date);
}

void task1b() {
    ChessField field;
    input_field(&field);
    print_field(field);
}

void task1c() {
    Rectangle rect;
    input_rectangle(&rect);
    print_rectangle(rect);
}

void task1d() {
    Polynomial poly;

    input_polynomial(&poly);
    print_polynomial(poly);

    free_polynomial(&poly);
}

void task2() {
    ChessField start, target;

    printf("Початкове поле (напр. a 1): ");
    scanf(" %c %d", &start.col, &start.row);

    printf("Цільове поле (напр. d 4): ");
    scanf(" %c %d", &target.col, &target.row);

    if (can_queen_move(start, target)) {
        printf("Так, ферзь МОЖЕ перейти на це поле за один хід.\n");
    } else {
        printf("Ні, ферзь НЕ МОЖЕ так піти.\n");
    }
}

void task3() {
    Date d;
    input_date(&d);

    Date next = get_tomorrow(d);
    printf("Завтра буде: %02d.%02d.%d\n", next.day, next.month, next.year);
    printf("День тижня цієї дати: %s\n", get_day_of_week(d));
}


// --- Допоміжні функції ---

bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int days_in_month(int m, int y) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && is_leap(y)) return 29;
    return days[m-1];
}

Date get_tomorrow(Date d) {
    d.day++;
    if (d.day > days_in_month(d.month, d.year)) {
        d.day = 1;
        d.month++;
        if (d.month > 12) {
            d.month = 1;
            d.year++;
        }
    }
    return d;
}

const char* get_day_of_week(Date d) {
    if (d.month < 3) {
        d.month += 12;
        d.year--;
    }
    int k = d.year % 100;
    int j = d.year / 100;
    int h = (d.day + 13*(d.month+1)/5 + k + k/4 + j/4 + 5*j) % 7;

    const char* days[] = {"Субота", "Неділя", "Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця"};
    return days[h];
}

void input_date(Date *d) {
    printf("Введіть дату (DD MM YYYY): ");
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

void print_date(Date d) {
    printf("Результат: %02d.%02d.%d\n", d.day, d.month, d.year);
}

void input_field(ChessField *f) {
    printf("Введіть поле (напр., b 2): ");
    scanf(" %c %d", &(f->col), &(f->row));
}

void print_field(ChessField f) {
    printf("Результат: %c%d\n", f.col, f.row);
}

void input_point(Point *p, const char *label) {
    printf("Введіть координати точки %s (x y): ", label);
    scanf("%lf %lf", &p->x, &p->y);
}

void input_rectangle(Rectangle *r) {
    input_point(&(r->p1), "A");
    input_point(&(r->p2), "B");
}

void print_rectangle(Rectangle r) {
    printf("Прямокутник задано точками:\n");
    printf("Точка A: (%.2lf, %.2lf)\n", r.p1.x, r.p1.y);
    printf("Точка B: (%.2lf, %.2lf)\n", r.p2.x, r.p2.y);
}

void input_polynomial(Polynomial *p) {
    printf("Введіть ступінь поліному: ");
    scanf("%d", &p->degree);

    // Виділяємо пам'ять під (n + 1) коефіцієнтів
    p->coeffs = (double*)malloc((p->degree + 1) * sizeof(double));


    printf("Введіть %d коефіцієнтів (від a0 до an):\n", p->degree + 1);
    for (int i = 0; i <= p->degree; i++) {
        printf("  a[%d] = ", i);
        scanf("%lf", &p->coeffs[i]);
    }
}

void print_polynomial(Polynomial p) {
    printf("P(x) = ");
    for (int i = p.degree; i >= 0; i--) {
        if (i < p.degree && p.coeffs[i] >= 0) printf("+");

        printf("%.2lfx^%d ", p.coeffs[i], i);
    }
    printf("\n");
}

void free_polynomial(Polynomial *p) {
    if (p->coeffs != NULL) {
        free(p->coeffs);
        p->coeffs = NULL;
    }
}

bool can_queen_move(ChessField s, ChessField t) {
    int dx = abs(s.col - t.col);
    int dy = abs(s.row - t.row);

    if (dx == 0 && dy == 0) return false; // те саме поле

    // Умова ферзя: або по прямій (dx чи dy рівні 0), або по діагоналі (dx == dy)
    return (dx == 0 || dy == 0 || dx == dy);
}

