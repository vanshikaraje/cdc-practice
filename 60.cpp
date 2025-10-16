#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2; // two stacks

public:
    MyQueue() {
        // Constructor (no initialization needed)
    }
    
    void push(int x) {
        // Always push into s1
        s1.push(x);
    }
    
    int pop() {
        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        // Same logic as pop, but don’t remove the element
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        // Queue is empty if both stacks are empty
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl; // 1
    cout << q.pop() << endl;  // 1
    cout << q.empty() << endl; // 0 (false)

    q.push(3);
    q.push(4);
    cout << q.pop() << endl;  // 2
    cout << q.peek() << endl; // 3
    return 0;
}
