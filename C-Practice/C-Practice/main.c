#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int arr[MAX_SIZE];

// 배열을 분할하는 함수
int partition(int arr[], int low, int high) {
    int temp;
    
    // 피벗을 배열의 가장 오른쪽 요소로 선택
    int pivot = arr[high];
    int i = (low - 1);  // 작은 요소들의 인덱스

    for (int j = low; j <= high - 1; j++) {
        // 현재 요소가 피벗보다 작으면, 작은 요소들을 한 쪽으로 모음
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    
    return (i + 1);
}

// 퀵 정렬 함수
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 배열을 분할하고 피벗의 위치를 얻음
        int pi = partition(arr, low, high);

        // 분할된 두 부분을 각각 정렬
        quickSort(arr, low, pi - 1); //왼쪽 퀵 정렬
        quickSort(arr, pi + 1, high); // 오른쪽 퀵정렬
    }
}

int main(void) {
    int n = MAX_SIZE;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
            arr[i] = rand() % 100;

    printf("정렬 전 배열: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\n정렬 후 배열: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
