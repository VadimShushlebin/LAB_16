#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"

double f(double x) {
    return x * x * x - 4 * x * x + 2;
}

double* full_elements(double* ptr_array, int n, double start, double step) {
    double x = start;
    for (int i = 0; i < n; i++) {
        ptr_array[i] = f(x);
        x += step;
    }
    return ptr_array;
}

int find(int* arr, int size, int type) {
    int fir = -1, last = -1;

    for (int i = 0; i < size; i++) {
        if ((type == 0 && arr[i] == 0) ||
            (type == 1 && arr[i] > 0) ||
            (type == 2 && arr[i] < 0)) {
            fir = i;
            break;
        }
    }

    for (int i = size - 1; i >= 0; i--) {
        if ((type == 0 && arr[i] == 0) ||
            (type == 1 && arr[i] > 0) ||
            (type == 2 && arr[i] < 0)) {
            last = i;
            break;
        }
    }

    if (fir == -1 || last == -1 || fir >= last) {
        return -1;
    }

    return fir + (last - fir) / 2;
}

double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (fabs(ptr_array[i] - element) < 0.000001) {
            return i;
        }
    }
    return -1;
}

int find_min(double* ptr_array, int n, double k) {
    int min_index = -1;

    for (int i = 0; i < n; i++) {
        if (fabs(fmod(ptr_array[i], k)) < 0.000001) {
            if (min_index == -1 || ptr_array[i] < ptr_array[min_index]) {
                min_index = i;
            }
        }
    }

    return min_index;
}

int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.3lf ", ptr_array[i]);
    }
    printf("\n");
    return n;
}

double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = -ptr_array[i];
    }
    return ptr_array;
}

int delete_k(double* ptr_arr, int size, int k) {
    if (k <= 0 || k > size) return size;

    int size2 = 0;
    for (int i = 0; i < size; i++) {
        if ((i + 1) % k != 0) {
            ptr_arr[size2] = ptr_arr[i];
            size2++;
        }
    }
    return size2;
}

double* insert_after_k(double* ptr_arr, int* size, int k) {
    if (k <= 0 || k > *size) return ptr_arr;

    int ins = (*size) / k;
    int size_n = *size + ins;

    double* new_arr = (double*)realloc(ptr_arr, size_n * sizeof(double));
    if (new_arr == NULL) {
        printf("Ошибка перевыделения памяти!\n");
        return ptr_arr;
    }

    for (int i = *size - 1, j = size_n - 1; i >= 0; i--, j--) {
        new_arr[j] = new_arr[i];
        if ((i + 1) % k == 0) {
            j--;
            new_arr[j] = -999.0;
        }
    }

    *size = size_n;
    return new_arr;
}
double* create_array_D(double* A, int n, double* C, int m, int* D_size) {

    int max_index = 0;
    for (int i = 1; i < m; i++) {
        if (C[i] > C[max_index]) {
            max_index = i;
        }
    }

    int pos_count = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            pos_count++;
        }
    }

    int tot_size = m + pos_count;


    double* D = (double*)malloc(tot_size * sizeof(double));
    if (D == NULL) {
        *D_size = 0;
        return NULL;
    }

    int d_index = 0;

    for (int i = 0; i < max_index; i++) {
        D[d_index++] = C[i];
    }

    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            D[d_index++] = A[i];
        }
    }

    for (int i = max_index; i < m; i++) {
        D[d_index++] = C[i];
    }

    *D_size = tot_size;
    return D;
}
