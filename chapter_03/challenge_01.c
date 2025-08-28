
#include <stdio.h>

// The below are function prototypes that inform the compiler about the existence of the functions.
// Without doing this, or putting these in a header file, the compiler won't recognize the functions, e.g
// call to undeclared function 'mergeSort'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
void mergeSort();
void _sortRecurse(int low, int high);
void _merge(int low, int mid, int high);
void quickSort();
void _quickSort(int low, int high);

double A[10] = {
    9.9,
    8.8,
    7.7,
    6.6,
    5.5,
    4.4,
    3.3,
    2.2,
    1.1,
    0.0
};

double A_copy[10];

int B[10] = {
    55,
    88,
    77,
    66,
    99,
    44,
    33,
    22,
    44,
    0
};

int main() {
    // mergeSort();
    quickSort();
    return 0;
}

void mergeSort() {
    int low = 0, high = 9;
    _sortRecurse(low, high);
    for (int i = 0; i < 10; i++) {
        printf("%f ", A[i]);
    }
}

void _sortRecurse(int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + ((high - low) / 2));
    _sortRecurse(low, mid);
    _sortRecurse(mid + 1, high);
    _merge(low, mid, high);
}

void _merge(int low, int mid, int high) {
    for (int i = low; i <= high; i++) {
        A_copy[i] = A[i];
    }

    int i = low;
    int j = mid + 1;

    for (int k = low; k <= high; k++) {
        if (i > mid) {
            A[k] = A_copy[j];
            j++;
        } else if (j > high) {
            A[k] = A_copy[i];
            i++;
        } else if (A_copy[j] < A_copy[i]) {
            A[k] = A_copy[j];
            j++;
        } else {
            A[k] = A_copy[i];
            i++;
        }
    }
}

void quickSort() {
    int low = 0, high = 9;
    _quickSort(low, high);
    for (int i = 0; i < 10; i++) {
        printf("%d ", B[i]);
    }
}

void _quickSort(int low, int high) {
    printf("low: %d\n", low);
    printf("high: %d\n", high);
    if (low >= high) {
        // printf("returning");
        return;
    }

    int i = low;
    int j = low;
    int k = high;
    int val = B[low];

    while (j <= k) {
        if (B[j] < val) {
            int temp = B[i];
            B[i] = B[j];
            B[j] = temp;
            i++;
            j++;
        } else if (B[j] > val) {
            int temp = B[k];
            B[k] = B[j];
            B[j] = temp;
            k -= 1;
        } else {
            j += 1;
        }
    }

    // printf("low: %d\n", low);
    // printf("i: %d\n", i);

    _quickSort(low, i - 1);
    _quickSort(j, high);
}