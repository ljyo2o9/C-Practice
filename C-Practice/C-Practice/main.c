#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int arr[], int n) {
    int k, i, j, temp; //k = gap n = 10;

    for (k = n / 2; k > 0; k /= 2) {
        if(k % 2 == 0) k++;
        for (i = k; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= k && arr[j - k] > temp; j -= k) {
                arr[j] = arr[j - k];
            }
            arr[j] = temp;
        }
    }
}

int main(void) {
    int arr[10];
    int n = 10;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("정렬 전 : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shellSort(arr, n);

    printf("정렬 후 : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
