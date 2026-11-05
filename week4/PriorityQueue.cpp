#include <iostream>
using namespace std;

const int MAX = 100;

struct PriorityQueue {
    int arr[MAX];
    int size;

    PriorityQueue() {
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void swim(int k) {
        int parent = (k - 1) / 2;
        while (k > 0 && arr[k] > arr[parent]) {
            swap(arr[k], arr[parent]);
            k = parent;
            parent = (k - 1) / 2;
        }
    }

    void sink(int k) {
        while (2 * k + 1 < size) {
            int j = 2 * k + 1; 
            if (j + 1 < size && arr[j + 1] > arr[j]) {
                j++;
            }
            if (arr[k] >= arr[j]) break;
            swap(arr[k], arr[j]);
            k = j;
        }
    }

    // them mot phan tu vao hang doi uu tien
    void push(int val) {
        if (size >= MAX) {
            return;
        }
        arr[size] = val;
        swim(size);
        size++;
    }

    // xoa phan tu co do uu tien cao nhat va tra ve gia tri cua no
    int pop() {
        if (isEmpty()) {
            return -1;
        }
        int maxVal = arr[0];
        arr[0] = arr[size - 1];
        size--;
        sink(0);
        return maxVal;
    }

    // xem phan tu co do uu tien cao nhat ma khong xoa
    int top() {
        if (isEmpty()) {
            return -1;
        }
        return arr[0];
    }

    int getSize() {
        return size;
    }
};


