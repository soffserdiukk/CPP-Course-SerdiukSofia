#include "rational.h"
#include <stdio.h>
#include <stdlib.h>

void print_rational(Rational r) {
    printf("%d/%u", r.numerator, r.denominator);
}

void input_rational(Rational *r) {
    printf("Введіть чисельник та знаменник4: ");
    scanf("%d %u", &r->numerator, &r->denominator);
    if (r->denominator == 0) {
        printf("Помилка: знаменник не може бути 0. Встановлено 1.\n");
        r->denominator = 1;
    }
}

Rational sum_rationals(Rational r1, Rational r2) {
    Rational r;
    r.numerator = r1.numerator * (int)r2.denominator + r2.numerator * (int)r1.denominator;
    r.denominator = r1.denominator * r2.denominator;
    reduce_rational(&r);
    return r;
}

Rational mult_rationals(Rational r1, Rational r2) {
    Rational r;
    r.numerator = r1.numerator * r2.numerator;
    r.denominator = r1.denominator * r2.denominator;
    reduce_rational(&r);
    return r;
}

bool compare_rationals(Rational r1, Rational r2) {
    return (r1.numerator * (int)r2.denominator == r2.numerator * (int)r1.denominator);
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        int t = a; a = b; b = t;
    }
    return a;
}

void reduce_rational(Rational *r) {
    int common = gcd(r->numerator, (int)r->denominator);
    r->numerator /= common;
    r->denominator /= (unsigned int)common;
}