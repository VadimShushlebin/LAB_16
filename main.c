#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#define N 10

int main() {
    system("chcp 1251");
    puts("Лабораторные работы 11, 14, 16: Работа с массивами\n");


    task11();

    int size;
    puts("Укажите размер массива");
    scanf("%d", &size);

    task14(size);
    task16(size);

    return 0;
}

void task11() {

    float A[N], B[N];
    float temp, summ = 0;

    // Задание 1. Заполнение массива с консоли
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
        summ += A[i];
    }

    // Задание 2. Преобразование массива
    for (int i = 0; i < N; i++) {
        B[i] = -A[i];
    }

    printf("|Индекс|Исходное значение|Новое значение|\n");
    for (int i = 0; i < N; i++) {
        printf("|%-6d|%17.2f|%14.2f|\n", i, A[i], B[i]);
    }

    // ДЗ. Вычисление среднего значения элементов с четными индексами
    int n;
    float D[100];
    printf("Введите размер списка: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%f", &D[i]);
    }

    int co = 0;
    float summ_dz = 0, sr_dz;
    for (int i = 2; i < n; i += 2) {
        summ_dz += D[i];
        co++;
    }

    sr_dz = summ_dz / co;
    printf("Среднее значение элементов, порядковые номера которых чётные: %.2f\n", sr_dz);
}

void task14(int size) {

    double* array = (double*)malloc(size * sizeof(double));
    if (array == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    // Задание 1. Заполнение массива значениями из функции f(x)
    full_elements(array, size);
    put_elements(array, size);

    // Задание 2. Преобразование массива
    printf("\n\nПреобразованный массив\n");
    calc_elements(array, size);
    put_elements(array, size);

    // Задание 3. Вычисление суммы элементов массива
    int begin, end;
    printf("\n\nВведите начальный индекс для суммирования: ");
    scanf("%d", &begin);
    printf("Введите конечный индекс для суммирования: ");
    scanf("%d", &end);
    printf("Сумма элементов %lf", sum_elements(array, begin, end));

    // Задание 4. Поиск в массиве значения равного elem
    double elem;
    printf("\n\nВведите число для поиска: ");
    scanf("%lf", &elem);
    printf("Индекс искомого числа: %d", find_element(array, size, elem));

    // Задание 5. Поиск порядкового номера минимального значения элементов, кратных k.
    int k;
    printf("\n\nВведите k для поиска минимального кратного элемента: ");
    scanf("%d", &k);
    int min_idx = find_min(array, size, k);
    printf("Индекс минимального элемента, кратного %d: %d\n", k, min_idx);

    free(array);

    
    int* arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nМассив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ДЗ. Поиск и вывод средних индексов
    printf("Индекс между положительными: %d\n", find(arr, size, 1));
    printf("Индекс между отрицательными: %d\n", find(arr, size, 2));
    printf("Индекс между нулевыми: %d\n", find(arr, size, 0));

    free(arr);
}


void task16(int size) {

    double* ptr_array1 = (double*)malloc(size * sizeof(double));
    if (ptr_array1 == NULL) {
        puts("Ошибка выделения памяти");
        return;
    }

    // Задание 1. Заполнение массива значениями функции f(x) 
    full_elements(ptr_array1, size);
    printf("Исходный массив:\n");
    put_elements(ptr_array1, size);

    // Задание 2. Преобразование массива
    calc_elements(ptr_array1, size);
    printf("Массив после преобразования:\n");
    put_elements(ptr_array1, size);

    free(ptr_array1);
    int k;

    double* ptr_array2 = (double*)malloc(size * sizeof(double));
    if (ptr_array2 == NULL) {
        puts("Ошибка выделения памяти");
        return;
    }

    // 3адание 3. Заполнение массива
    full_elements_task2(ptr_array2, size);
    printf("Получившийся массив:\n");
    put_elements(ptr_array2, size);

    // Задание 4. Удаление каждого k-го элемента
    printf("Введите k для удаления каждого k-го элемента: ");
    scanf("%d", &k);
    int size_after_delete = delete_k(ptr_array2, size, k);
    printf("Массив после удаления каждого %d-го элемента:\n", k);
    put_elements(ptr_array2, size_after_delete);
    printf("Новый размер массива: %d\n", size_after_delete);

    // Задание 5. Вставка -999 после каждого k-го элемента
    printf("\nВведите k для вставки -999 после каждого k-го элемента: ");
    scanf("%d", &k);
    ptr_array2 = insert_after_k(ptr_array2, &size_after_delete, k);
    printf("Массив после вставки -999 после каждого %d-го элемента:\n", k);
    put_elements(ptr_array2, size_after_delete);
    printf("Новый размер массива: %d\n", size_after_delete);

    free(ptr_array2);
}