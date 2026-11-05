#include <iostream>
using namespace std;

void sink(int arr[], int n, int i) {
    while (2 * i + 1 < n) {
        int j = 2 * i + 1;
        if (j + 1 < n && arr[j + 1] > arr[j]) {
            j++; 
        }
        if (arr[i] >= arr[j]) break;
        swap(arr[i], arr[j]);
        i = j;
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        sink(arr, n, i);
    }
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        sink(arr, i, 0);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

