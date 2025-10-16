#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
private:
    vector<int> q;  // fixed-size array
    int front;      // front pointer
    int rear;       // rear pointer
    int size;       // maximum capacity
    int count;      // current number of elements

public:
    MyCircularQueue(int k) {
        q.resize(k);
        size = k;
        front = 0;
        rear = -1;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;          // cannot insert if full
        rear = (rear + 1) % size;            // circular increment
        q[rear] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;         // cannot remove if empty
        front = (front + 1) % size;          // circular increment
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};

int main() {
    MyCircularQueue myCircularQueue(3);
    cout << boolalpha;  // print true/false instead of 1/0

    cout << myCircularQueue.enQueue(1) << endl; // true
    cout << myCircularQueue.enQueue(2) << endl; // true
    cout << myCircularQueue.enQueue(3) << endl; // true
    cout << myCircularQueue.enQueue(4) << endl; // false
    cout << myCircularQueue.Rear() << endl;     // 3
    cout << myCircularQueue.isFull() << endl;   // true
    cout << myCircularQueue.deQueue() << endl;  // true
    cout << myCircularQueue.enQueue(4) << endl; // true
    cout << myCircularQueue.Rear() << endl;     // 4

    return 0;
}
