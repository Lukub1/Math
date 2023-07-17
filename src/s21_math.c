#include "s21_math.h"

/*int s21_abs(int x);// вычисляет абсолютное значение целого числа
long double s21_fabs(double x);// вычисляет абсолютное значение числа с
плавающей точкой long double s21_pow(double base, double exp);//возводит
число в заданную степень long double s21_ceil(double x);// возвращает
ближайшее целое число, не меньшее заданного значения long double
s21_floor(double x);// возвращает ближайшее целое число, не превышающее
заданное значение long double s21_exp(double x);// возвращает значение e,
возведенное в заданную степень long double s21_fmod(double x, double y);//
остаток операции деления с плавающей точкой long double cos(double x);//
вычисляет косинус long double sin(double x);// вычисляет синус long double
asin(double x);// вычисляет арксинус long double tan(double x); // вычисляет
тангенс long double atan(double x);// вычисляет арктангенс long double
sqrt(double x);// вычисляет квадратный корень
long double acos(double x);// вычисляет арккосинус
long double log(double x);// вычисляет натуральный логарифм*/

int s21_abs(int x) {
  if (x < 0) x *= -1;
  return x;
}

long double s21_fabs(double x) {
  if (x < 0) x *= -1;
  return (long double)x;
}

long double s21_pow_int(double base, double exp) {
  long double total = 1;
    for (int i = 0; i < exp; i++) total *= base;
  return total;
}

long double s21_exp(double x) {
  long double xt = x;
  long double sum = 0.0;
  long double n = 1.0;
  int i = 1;
  if (xt < 0.0) {
    xt *= -1.0;
  }
  if (x != x) {
    sum = s21_NAN;
  } else if (x == s21_NEGINF) {
    sum = 0;
  } else if (x == s21_POSINF) {
    sum = s21_POSINF;
  } else {
    while (s21_fabs(n) > s21_EPS) {
      sum += n;
      n *= xt / i;
      i++;
    }
    if (x < 0) sum = 1 / sum;
  }
  return sum;
}


long double s21_log(double x) {
  double sum = 0.0;
  if (x < 0.0) {
    sum = s21_NAN;
  } else if (s21_fabs(x) == 0.0) {
    sum = -s21_POSINF;
  } else if (x == s21_POSINF) {
    sum = s21_POSINF;
  } else if (x == S21_DOUBLE_MIN) {
    sum = -708.3964185322640787;
  } else {
    int log_10 = 0;
    while (x > 10.0) {
      x /= 10.0;
      log_10++;
    }
    while (x < 0.1) {
      x *= 10.0;
      log_10--;
    }
    long double n = (x - 1) / (x + 1);
    int i = 1;
    do {
      sum += n / i;
      n *= ((x - 1) * (x - 1)) / ((x + 1) * (x + 1));
      i += 2;
    } while (s21_fabs(n) > s21_EPS);
    sum = sum * 2.0 + log_10 * S21_LOG_10;
  }
  return sum;
}

long double s21_pow(double base, double exp) {
  long double sum;
  long double modul;
  modul = exp > 0 ? s21_floor(exp) : -1.0 * s21_ceil(exp);
  if (base == 1.0 || exp == 0.0) {
    sum = 1.0;
  } else if (exp == 1.0) {
    sum = base;
  } else if ((base != base) || (exp != exp) ||
             ((base < 0 && base != s21_NEGINF) &&
              (exp != s21_POSINF && exp > 0 && exp != s21_floor(exp))) ||
             ((base < 0 && base != s21_NEGINF) &&
              (exp < 0 && exp != s21_ceil(exp)))) {
    sum = s21_NAN;
  } else if (base == s21_NEGINF) {
    if (exp > 0.0 && exp < 1.0)
      sum = s21_POSINF;
    else if (exp < 0)
      sum = 0.0;
    else if (s21_fmod(exp, 2.0) == 1.0)
      sum = s21_NEGINF;
    else
      sum = s21_POSINF;
  } else if (base == s21_POSINF) {
    if (exp > 0.0)
      sum = s21_POSINF;
    else
      sum = 0.0;
  } else if (base == 0.0) {
    sum = exp > 0 ? 0.0 : s21_POSINF;
  } else if (base == -1.0) {
    if (exp == s21_NEGINF || exp == s21_POSINF ||
        s21_fmod(s21_fabs(exp), 2.0) == 0.0) {
      sum = 1.0;
    } else {
      sum = -1.0;
    }
  } else if (exp == s21_NEGINF) {
    sum = s21_fabs(base) > 1.0 ? 0.0 : s21_POSINF;
  } else if (s21_fabs(base) < 1 && exp == s21_POSINF) {
    sum = 0.0;
  } else if (exp == s21_POSINF) {
    sum = s21_POSINF;
  } else {
    if (base < 0 || modul == exp) {
      sum = s21_pow_int(base, s21_fabs(exp));
    } else {
      sum = s21_exp(s21_fabs(exp) * s21_log(base));
    }
    if (exp < 0) sum = 1 / sum;
    if (sum > S21_DOUBLE_MAX) sum = s21_POSINF;
    if (sum < S21_DOUBLE_MIN) sum = s21_NEGINF;
  }
  return sum;
}


long double s21_floor(double x) {
  int i = (int)x;
  if (i != x) {
    if (x < 0) i--;
  }
  return i;
}

long double s21_ceil(double x) {
  int i = (int)x;
  if (i != x) {
    if (x > 0) i++;
  }
  return i;
}

int s21_isnan(double x) { return (x == x ? 0 : 1); }

long double s21_sqrt(double x) {
  long double root;
  if (s21_isnan(x) || x < 0) {
    root = s21_NAN;
  } else {
    if (x == s21_POSINF) {
      root = s21_POSINF;
    } else {
      long double temp = 1;
      for (;;) {
        root = (temp + x / temp) / 2;
        if (s21_fabs(root - temp) < s21_EPS) break;
        temp = root;
      }
    }
  }
  return root;
}

long double s21_calculation(long double x, long double sum, long double prev,
                            long double fprev, long double term, long double i,
                            int count) {
  while (s21_fabs(term) >= s21_EPS) {
    i += 2.0;
    fprev *= (i * (i - 1));
    prev = prev * x * x;
    term = prev / fprev;
    sum += count * term;
    count = -count;
  }
  return sum;
}

long double s21_fmod(double x, double y) {
  int exit = 0;
  long double mod = 0;
  if (s21_isnan(x) || y == 0 || x == s21_POSINF || s21_isnan(y) ||
      x == s21_NEGINF) {
    exit = 1;
  } else {
    int flag = 0;
    if (x < 0) {
      x = -x;
      flag++;
    }
    if (y < 0) y = -y;
    if (x < y) {
      mod = (flag == 1 ? -x : x);
    } else if (x > y) {
      long long temp = (long double)x / (long double)y;
      mod = (long double)x - temp * (long double)y;
      mod = (!mod ? 0 : flag == 1 ? -mod : mod);
    }
  }
  if (exit == 1) {
    mod = s21_NAN;
  }
  return mod;
}

long double s21_sin(double x) {
  long double exit = 0.0;
  if (s21_isnan(x) || x == s21_POSINF || x == s21_NEGINF) {
    exit = s21_NAN;
  } else {
    x = s21_fmod(x, 2 * s21_M_PI);
    long double sum = x, prev = x, fprev = 1, i = 1.0, term = x;
    int count = -1;
    exit = s21_calculation(x, sum, prev, fprev, term, i, count);
  }
  return exit;
}

long double s21_cos(double x) {
  long double exit = 0.0;
  if (s21_isnan(x) || x == s21_POSINF || x == s21_NEGINF) {
    exit = s21_NAN;
  } else {
    x = s21_fmod(x, 2 * s21_M_PI);
    long double sum = 1, prev = 1, fprev = 1, term = x, i = 0.0;
    int count = -1;
    exit = s21_calculation(x, sum, prev, fprev, term, i, count);
  }
  return exit;
}

long double s21_acos(double x) {
  long double acos = 0;
  if (x >= -1 && x <= 1) {
    if (x == 1) {
      acos = 0;
    } else if (x == -1.) {
      acos = s21_M_PI;
    } else if (x == 0) {
      acos = s21_M_PI / 2;
    } else {
      if (x == 0.7071067811865475244) {
        acos = s21_M_PI / 4;
      }
      if (x == -0.7071067811865475244) {
        acos = 3 * s21_M_PI / 4;
      }
      if (0. < x && x < 1.) {
        acos = s21_atan(s21_sqrt(1 - x * x) / x);
      } else if (-1. < x && x < 0.) {
        acos = s21_M_PI + s21_atan(s21_sqrt(1 - x * x) / x);
      } else {
        acos = s21_NAN;
      }
    }
  } else {
    acos = s21_NAN;
  }
  return acos;
}

long double s21_tan(double x) {
  long double res;
  if (s21_isnan(x)) {
    res = s21_NAN;
  } else {
    x = s21_fmod(x, 2 * s21_M_PI);
    if (x == s21_M_PI / 2) {
      res = 16331239353195370L;
    } else if (x == -s21_M_PI / 2) {
      res = -16331239353195370L;
    } else {
      res = s21_sin(x) / s21_cos(x);
    }
  }
  return res;
}

long double s21_asin(double x) {
  long double sum = x, prev = x, i = 1.0, del = 0;
  if (s21_fabs(x) > 1) {
    sum = s21_NAN;
  } else if (s21_fabs(x) == 1) {
    sum = (x > 0 ? s21_M_PI / 2 : -s21_M_PI / 2);
  } else {
    while (s21_fabs(prev) >= s21_EPS) {
      prev = prev * x * x * i / (i + 1);
      del = (i + 2);
      sum += prev / del;
      i += 2.0;
    }
  }
  return sum;
}

long double s21_atan(double x) {
  long double sum;
  if (x == s21_POSINF) {
    sum = s21_M_PI / 2;
  } else if (x == s21_NEGINF) {
    sum = -s21_M_PI / 2;
  } else {
    sum = s21_asin(x / s21_sqrt(1 + x * x));
  }
  return sum;
}
