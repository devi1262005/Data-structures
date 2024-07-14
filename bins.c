#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Key found, return its index
        }

        if (arr[mid] < key) {
            low = mid + 1;
        }
         else {
            high = mid - 1;
        }
    }

    return -1; // Key not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

