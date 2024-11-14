//c
//11 лаба
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  
#include <stdlib.h>  
#include <locale.h>  
#include <math.h>  

#define N 10  
#define SIZE 100  

// Функция для вычисления значения по заданной формуле 
float calculate_function(float x) {
    return x * x - cos(x + 1) * cos(x + 1);
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    // Задание 1: Работа с массивом вещественных чисел 
    float A[N], temp;
    float B[N];
    float sum = 0.0;

    // Заполнение массива с консоли 
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf_s("%f", &temp);
        A[i] = temp;
        sum += A[i]; // Суммируем для среднего арифметического 
    }

    // Преобразование массива (уменьшение в 10 раз) 
    for (int i = 0; i < N; i++) {
        B[i] = A[i] / 10; // Уменьшение значения каждого элемента 
    }

    // Вывод результатов в виде таблицы 
    printf("| индекс | исходное значение | новое значение |\n");
    for (int i = 0; i < N; i++) {
        printf("|   %2d   |      %.2f       |     %.2f      |\n", i + 1, A[i], B[i]);
    }

    // Среднее арифметическое 
    printf("Среднее арифметическое элементов массива: %.2f\n", sum / N);

    // Задание 2: Генерация массива из 100 вещественных значений 
    float array[SIZE];
    float sum_positive = 0.0, sum_negative = 0.0;
    int count_positive = 0, count_negative = 0;

    for (int i = 0; i < SIZE; i++) {
        float x = 0.1 + i * (2.2 - 0.1) / (SIZE - 1);
        array[i] = calculate_function(x);

        if (array[i] > 0) {
            sum_positive += array[i];
            count_positive++;
        }
        else {
            sum_negative += array[i];
            count_negative++;
        }
    }

    float average_positive = count_positive ? sum_positive / count_positive : 0;

    // Вывод результатов 
    printf("nИмя массива: arrayn");
    printf("Накопленное значение положительных: %.2f\n", sum_positive);
    printf("Накопленное значение отрицательных: %.2f\n", sum_negative);
    printf("Количество положительных элементов: %d\n", count_positive);
    printf("Количество отрицательных элементов: %d\n", count_negative);
    printf("Среднее значение положительных элементов: %.2f\n", average_positive);

    // Задание 3: Работа с одномерным массивом целых чисел 
    int n, A_int;
    int int_array[N];

    printf("nВведите количество элементов массива (максимум %d): ", N);
    scanf_s("%d", &n);

    if (n > N) {
        n = N; // Ограничиваем количество элементов 
        printf("Количество элементов не может превышать %d. Установлено на %d.\n", N, N);
    }

    printf("Введите элементы массива:n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &int_array[i]);
    }

    printf("Введите число A: ");
    scanf_s("%d", &A_int);

    int count_greater = 0;

    for (int i = 0; i < n; i++) {
        if (int_array[i] > A_int) {
            count_greater++;
        }
    }

    printf("Количество элементов массива, значение которых больше %d: %d\n", A_int, count_greater);

    return 0;
}
