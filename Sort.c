#include <stdio.h>

void printArray(int *a, int l) {
    int i;
    for (i = 0; i < l; i++)
        printf("%d ", a[i]);
    printf("\n");
};

// 直接插入排序
void directInsertionSort(int *a, int l) {
    int i, j, k;
    int tmp;
    for (i = 1; i < l; i++) {
        for (j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                tmp = a[i];
                for (k = i; k > j; k--)
                    a[k] = a[k-1];
                a[j] = tmp;
                break;// 如果不跳出循环，会多出i-j次无意义的比较
            };
        };
    };
};

// 归并排序
void mergeSort(int *a, int l) {
};

// 堆排序
void heapSort(int *a, int l) {
};

// 基数排序
void radixSort(int *a, int l) {
};

// 希尔排序
void shellSort(int *a, int l) {
};

// 地精排序
void gnomeSort(int *a, int l) {
    int i = 0;
    int tmp;
    while (i < l) {
        if (i == 0 || a[i] > a[i-1])
            i++;
        else {
            tmp = a[i];
            a[i] = a[i-1];
            a[i-1] = tmp;
            i--;
        };
    };
};

// 双向冒泡排序
void cocktailShakerSort(int *a, int l) {
    if (l < 2)
        return;
    else {
        int i;
        int tmp;
        for (i = 1; i < l; i++) {
            if (a[i-1] > a[i]) {
                tmp = a[i-1];
                a[i-1] = a[i];
                a[i] = tmp;
            };
        };
        for (i = l-2; i > 0; i--) {
            if (a[i] < a[i-1]) {
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
            };
        };
        cocktailShakerSort(&a[1], l - 2);
    };
};

// 冒泡排序
void bubbleSort(int *a, int l) {
    int i, j;
    int tmp;
    for (i = l; i > 0; i--) {
        for (j = 0; j < i-1; j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            };
        };
    };
};

// 简单选择排序
void simpleSelectionSort(int *a, int l) {
    int i, j, min;
    int tmp;
    for (i = 0; i < l-1; i++) {
        min = i;
        for (j = i+1; j < l; j++) {
            if (a[j] < a[min])
                min = j;
            if (min != i) {
                tmp = a[min];
                a[min] = a[i];
                a[i] = tmp;
            };
        };
    };
};

// 快速排序
void quickSort(int *a, int l) {
    if (l < 2)
        return;
    else {
        int index = 0;
        int i, j;
        int tmp;
        for (i = 1; i < l; i++) {
            if (a[i] < a[index]) {
                tmp = a[i];
                for (j = i; j > 0; j--)
                    a[j] = a[j-1];
                a[0] = tmp;
                index++;
            };
        };
        quickSort(a, index);
        quickSort(&a[index+1], l - index - 1);
    };
};

int main() {
    int arr[20] = {5, 9, 13, 15, 12, 18, 2, 1, 4, 7, 6, 8, 3, 10, 17, 20, 11, 14, 16, 19};
    printArray(arr, 20);
    //quickSort(arr, 20);
    //bubbleSort(arr, 20);
    //simpleSelectionSort(arr, 20);
    //directInsertionSort(arr, 20);
    //cocktailShakerSort(arr ,20);
    gnomeSort(arr ,20);
    printArray(arr, 20);
    return 0;
}
