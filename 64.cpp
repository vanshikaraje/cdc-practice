#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;      // main stack
    stack<int> minSt;   // stack to track minimums

public:
    MinStack() {
        // Nothing needed here
    }

    void push(int val) {
        st.push(val);
        // Push to minSt if empty or val <= current minimum
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << minStack.top() << endl;    // 0
    cout << minStack.getMin() << endl; // -2

    return 0;
}
