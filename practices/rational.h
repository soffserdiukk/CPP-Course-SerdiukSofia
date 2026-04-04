

#ifndef CPP_COURSE_SERDIUKSOFIA_RATIONAL_H
#define CPP_COURSE_SERDIUKSOFIA_RATIONAL_H

#include <stdbool.h>

typedef struct {
    int numerator;
    unsigned int denominator;
} Rational;

extern void print_rational(Rational r);

extern void input_rational(Rational *r);

Rational sum_rationals(Rational r1, Rational r2);
Rational div_rationals(Rational r1, Rational r2);
Rational mult_rationals(Rational r1, Rational r2);

bool compare_rationals(Rational r1, Rational r2);

void reduce_rational(Rational *r);

#endif //CPP_COURSE_SERDIUKSOFIA_RATIONAL_H