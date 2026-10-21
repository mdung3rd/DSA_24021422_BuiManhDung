#include <iostream>
using namespace std;
#include "../week1/List.cpp"
#include "../week1/LinkedList.cpp"

// cach 1: dung list
struct ListStack {
    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    void push(int item) {
        insertLast(item);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return -1;
        }
        int val = getAt(n - 1); 
        deleteLast();           
        return val;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return -1;
        }
        return getAt(n - 1);
    }
};

// cach 2: dung linked list

struct LinkedListStack {
    Node* head;
    int count;

    LinkedListStack() {
        head = nullptr;
        count = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        return count;
    }

    void push(int item) {
        insertFirst(head, item);
        count++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return -1;
        }
        int val = getAt(head, 0); 
        deleteFirst(head);        
        count--;
        return val;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return -1;
        }
        return getAt(head, 0);
    }
};
