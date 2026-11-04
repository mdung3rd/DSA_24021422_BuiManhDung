#include <iostream>
using namespace std;

// Ham chim xuong (sink) de duy tri tinh chat Max-Heap cho mang co n phan tu tai nut i
void sink(int arr[], int n, int i) {
    while (2 * i + 1 < n) {
        int j = 2 * i + 1; // con ben trai
        if (j + 1 < n && arr[j + 1] > arr[j]) {
            j++; // chon con lon hon giua con trai va con phai
        }
        if (arr[i] >= arr[j]) break;
        swap(arr[i], arr[j]);
        i = j;
    }
}

// Ham Heap Sort
void heapSort(int arr[], int n) {
    // Buoc 1: Xay dung Max-Heap tu mang ban dau (chay tu nut cha cuoi cung ve goc)
    for (int i = n / 2 - 1; i >= 0; i--) {
        sink(arr, n, i);
    }

    // Buoc 2: Lan luot dua phan tu lon nhat o goc ve cuoi mang va thu hep kich thuoc heap
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

