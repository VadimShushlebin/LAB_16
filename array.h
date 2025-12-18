#ifndef ARRAY_H
#define ARRAY_H

/**
 * Функция для вычисления значения f(x) = x^3 - 4x^2 + 2
 * @param x аргумент функции
 * @return значение функции
 */
double f(double x);

/**
 * Заполнение массива значениями из функции f(x) с заданными параметрами
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param start начальное значение x
 * @param step шаг изменения x
 * @return указатель на заполненный массив
 */
double* full_elements(double* ptr_array, int n, double start, double step);

/**
 * Печать элементов массива
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return количество выведенных элементов
 */
int put_elements(double* ptr_array, int n);

/**
 * Преобразование элементов массива (умножение на -1)
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @return указатель на преобразованный массив
 */
double* calc_elements(double* ptr_array, int n);

/**
 * Поиск среднего индекса между элементами определенного типа
 * @param arr указатель на массив
 * @param size размер массива
 * @param type тип элементов: 0 - нулевые, 1 - положительные, 2 - отрицательные
 * @return индекс между найденными элементами или -1 если не найдено
 */
int find(int* arr, int size, int type);

/**
 * Вычисление суммы элементов массива от индекса begin до индекса end включительно
 * @param ptr_array указатель на массив
 * @param begin начальный индекс
 * @param end конечный индекс
 * @return сумма элементов
 */
double sum_elements(double* ptr_array, int begin, int end);

/**
 * Поиск элемента равного заданному значению в массиве
 * Используется в лабораторной работе 14
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param element искомый элемент
 * @return индекс найденного элемента или -1 если элемент не найден
 */
int find_element(double* ptr_array, int n, double element);

/**
 * Поиск порядкового номера минимального значения элементов, кратных k
 * @param ptr_array указатель на массив
 * @param n размер массива
 * @param k число, кратность которому проверяется
 * @return индекс минимального кратного элемента или -1 если таких элементов нет
 */
int find_min(double* ptr_array, int n, double k);

/**
 * Удаление каждого k-го элемента из массива
 * @param ptr_arr указатель на массив
 * @param size размер массива
 * @param k номер удаляемого элемента
 * @return новый размер массива после удаления
 */
int delete_k(double* ptr_arr, int size, int k);

/**
 * Вставка значения -999 после каждого k-го элемента
 * @param ptr_arr указатель на массив
 * @param size указатель на размер массива (будет изменен)
 * @param k номер элемента после которого выполняется вставка
 * @return указатель на новый массив
 */
double* insert_after_k(double* ptr_arr, int* size, int k);

/**
 * Создание массива D из элементов массива C, а также положительными элементами из массива A перед максимальным элементом массива D
 * @param A исходный массив A
 * @param n размер массива A
 * @param D_size указатель на переменную для размера нового массива D
 * @return указатель на новый массив D
 */
double* create_array_D(double* A, int n, double* C, int m, int* D_size);

/**
 * Выполнение лабораторной работы 11 (3 задания)
 */
void task11();

/**
 * Выполнение лабораторной работы 14
 * @param size размер массива
 */
void task14(int size);

/**
 * Выполнение лабораторной работы 16
 * @param size размер массива
 */
void task16(int size);

#endif
