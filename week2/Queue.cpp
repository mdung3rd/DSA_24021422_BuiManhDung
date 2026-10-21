#include <iostream>
using namespace std;
#include "../week1/List.cpp"
#include "../week1/LinkedList.cpp"

//cach 1: dung list

struct LinkQueue {
    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    void enqueue(int item) {
        insertLast(item);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong" << endl;
            return -1;
        }
        int val = getAt(0); 
        deleteFirst();      
        return val;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong" << endl;
            return -1;
        }
        return getAt(0);
    }
};

// cach 2: dung linked list

struct LinkedListQueue {
    Node* head;
    int count;

    LinkedListQueue() {
        head = nullptr;
        count = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int size() {
        return count;
    }

    void enqueue(int item) {
        insertLast(head, item);
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong" << endl;
            return -1;
        }
        int val = getAt(head, 0);
        deleteFirst(head);        
        count--;
        return val;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong" << endl;
            return -1;
        }
        return getAt(head, 0);
    }
};

