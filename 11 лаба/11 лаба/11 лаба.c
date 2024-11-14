//c
//11 ����
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  
#include <stdlib.h>  
#include <locale.h>  
#include <math.h>  

#define N 10  
#define SIZE 100  

// ������� ��� ���������� �������� �� �������� ������� 
float calculate_function(float x) {
    return x * x - cos(x + 1) * cos(x + 1);
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    // ������� 1: ������ � �������� ������������ ����� 
    float A[N], temp;
    float B[N];
    float sum = 0.0;

    // ���������� ������� � ������� 
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf_s("%f", &temp);
        A[i] = temp;
        sum += A[i]; // ��������� ��� �������� ��������������� 
    }

    // �������������� ������� (���������� � 10 ���) 
    for (int i = 0; i < N; i++) {
        B[i] = A[i] / 10; // ���������� �������� ������� �������� 
    }

    // ����� ����������� � ���� ������� 
    printf("| ������ | �������� �������� | ����� �������� |\n");
    for (int i = 0; i < N; i++) {
        printf("|   %2d   |      %.2f       |     %.2f      |\n", i + 1, A[i], B[i]);
    }

    // ������� �������������� 
    printf("������� �������������� ��������� �������: %.2f\n", sum / N);

    // ������� 2: ��������� ������� �� 100 ������������ �������� 
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

    // ����� ����������� 
    printf("n��� �������: arrayn");
    printf("����������� �������� �������������: %.2f\n", sum_positive);
    printf("����������� �������� �������������: %.2f\n", sum_negative);
    printf("���������� ������������� ���������: %d\n", count_positive);
    printf("���������� ������������� ���������: %d\n", count_negative);
    printf("������� �������� ������������� ���������: %.2f\n", average_positive);

    // ������� 3: ������ � ���������� �������� ����� ����� 
    int n, A_int;
    int int_array[N];

    printf("n������� ���������� ��������� ������� (�������� %d): ", N);
    scanf_s("%d", &n);

    if (n > N) {
        n = N; // ������������ ���������� ��������� 
        printf("���������� ��������� �� ����� ��������� %d. ����������� �� %d.\n", N, N);
    }

    printf("������� �������� �������:n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &int_array[i]);
    }

    printf("������� ����� A: ");
    scanf_s("%d", &A_int);

    int count_greater = 0;

    for (int i = 0; i < n; i++) {
        if (int_array[i] > A_int) {
            count_greater++;
        }
    }

    printf("���������� ��������� �������, �������� ������� ������ %d: %d\n", A_int, count_greater);

    return 0;
}
