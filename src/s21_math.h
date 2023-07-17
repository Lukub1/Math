#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define s21_M_PI 3.141592
#define s21_EXP 2.718281828
#define s21_EPS 0.000000000001
#define s21_NAN 0.0 / 0.0
#define s21_POSINF 1.0 / 0.0
#define s21_NEGINF -1.0 / 0.0
#define S21_DOUBLE_MAX 1.7E+308
#define S21_DOUBLE_MIN 1.7E-308
#define S21_LOG_10 2.3025850930

int s21_abs(int x);  // вычисляет абсолютное значение целого числа
long double s21_fabs(
    double x);  // вычисляет абсолютное значение числа с плавающей точкой
long double s21_pow(double base,
                    double exp);  // возводит число в заданную степень
long double pow_for_int(double base, double exp);
long double pow_for_frac(double base, double exp);
long double s21_ceil(double x);  // возвращает ближайшее целое число, не меньшее
                                 // заданного значения
long double s21_floor(double x);  // возвращает ближайшее целое число, не
                                  // превышающее заданное значение
long double s21_exp(
    double x);  // возвращает значение e, возведенное в заданную степень
long double s21_log(double x);  // вычисляет натуральный логарифм
long double s21_fmod(double x,
                     double y);  // остаток операции деления с плавающей точкой
long double s21_cos(double x);   // вычисляет косинус
long double s21_acos(double x);  // вычисляет арккосинус
long double s21_sin(double x);   // вычисляет синус
long double s21_asin(double x);  // вычисляет арксинус
long double s21_tan(double x);   // вычисляет тангенс
long double s21_atan(double x);  // вычисляет арктангенс
long double s21_sqrt(double x);  // вычисляет квадратный корень
long double s21_calculation(long double x, long double sum, long double prev,
                            long double fprev, long double term, long double i,
                            int count);
int s21_isnan(double x);

#endif  // SRC_S21_MATH_H_
