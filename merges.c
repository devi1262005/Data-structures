#include <stdio.h>

int i = 0, j = 0, k = 0, c[10];

void merge(int *a, int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    while (i <= mid)
        c[k++] = a[i++];

    while (j <= high)
        c[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = c[i];
}

void mergesort(int *a, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[30], i, b[30];
    printf("Enter the number of elements for array a (5 elements expected):\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, 4);
    printf("Sorted array for a:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\nEnter the number of elements for array b (5 elements expected):\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &b[i]);
    }
    mergesort(b, 0, 4);
    printf("Sorted array for b:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}
hh
