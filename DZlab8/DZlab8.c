#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // не работает #include <locale.h>

double calculate_series(double a, int n);
int main() {
    SetConsoleOutputCP(65001);
    double a;
    int n;
    printf("Вычисление ряда: a(a - n)(a - 2n) ... (a - n^2)\n\n");

    printf("Введите значение a: ");
    scanf("%lf", &a);

    printf("Введите значение n: ");
    scanf("%d", &n);

    double result = calculate_series(a, n);
    printf("\nРезультат вычисления ряда: %.4lf\n", result);
    return 0;
}


double calculate_series(double a, int n) {

    double prod = 1.0;
    for (int i = 1; i <= n; i = i + 1) {
        double bracket = a - (i * n);
        prod = prod * bracket;
        printf("Шаг %d: умножаем на (%.1lf - %d*%d) = %.1lf\n", i, a, i, n, bracket);
    }
    return prod;
}