#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // не работает #include <locale.h>

int print_symbols();
int calculate_sum(int m, int n);
double calculate_function(double x);

int main() {
    SetConsoleOutputCP(65001);

    // --- ЗАДАНИЕ 0 ---
    printf("ЗАДАНИЕ 0:\n");
    print_symbols(); 
    printf("\n______________________________________\n\n\n");

    // --- ЗАДАНИЕ 1 ---
    printf("ЗАДАНИЕ 1: \n!!!Верхняя граница(m) не может быть меньше нижней(n)!!!\n");

    int n, m;
    printf("Введите число n (нижняя граница): ");
    scanf("%d", &n);
    printf("Введите число m (верхняя граница): ");
    scanf("%d", &m);

    printf("\nНачинаем цикл:\n");
    int total_sum = calculate_sum(m, n);
    printf("\nИтоговый результат: %d", total_sum);
    printf("\n______________________________________\n\n");

    // --- ЗАДАНИЕ 2 ---
    printf("\nЗАДАНИЕ 2:\n");
    printf("Табулирование функции: y = x^3 - 4x^2 + 2\n");
    printf("Интервал: [1; 3]\n\n");

    double step;
    printf("Введите шаг табуляции (например, 0.5): ");
    scanf("%lf", &step);

    if (step <= 0) {
        printf("Ошибка: шаг должен быть больше нуля!\n");
        return 1;
    }

    printf("\n_________________________\n");
    printf("|    x     |    f(x)    |\n");

    double x_start = 1.0;
    double x_end = 3.0;


    for (double x = x_start; x <= x_end + 1e-9; x = x + step) {
        double y = calculate_function(x);
        printf("| %8.2lf | %10.4lf |\n", x, y);
    }

    return 0;
}



// ЗАДАНИЕ 0
int  print_symbols() {
    putchar('+');
    for (int start = 1; start <= 10; start++) {
        putchar('*');
    }
    putchar('+');
    printf("\n");

    for (int start = 1; start <= 10; start++) {
        putchar('*');
        putchar('!');
    }
    printf("\n");

    for (int start = 1; start <= 10; start++) {
        if (start <= 5) {
            putchar('*');
        }
        else {
            putchar('#');
        }
    }
}

// ЗАДАНИЕ 1
int calculate_sum(int m, int n) {
    int s = 0;
    int k = 0;

    for (int i = m; i >= n; i = i - 1) {
        s = s + i;
        k = k + 1;
        printf("Выполнено %d раз (добавили число %d, сумма стала %d)", k, i, s);
    }
    return s;
}

// ЗАДАНИЕ 2
double calculate_function(double x) {
    return (x * x * x) - (4.0 * x * x) + 2.0;
}
