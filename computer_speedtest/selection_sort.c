#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n = 200000; // 50,000 elements
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    // Seed random number generator
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    printf("Sorting %d integers using Selection Sort...\n", n);

    clock_t start = clock();
    selection_sort(arr, n);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sort completed in: %f seconds\n", cpu_time_used);

    free(arr);
    return 0;
}
