#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int a = 0;  // F(0)
        int b = 1;  // F(1)
        int result = 0;

        for (int i = 2; i <= n; i++) {
            result = a + b; // F(i) = F(i-1) + F(i-2)
            a = b;          // Move forward
            b = result;
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    cout << "Fibonacci(" << n << ") = " << obj.fib(n) << endl;

    return 0;
}
