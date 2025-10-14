#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int factorial(int n) {
        if (n == 0 || n == 1) return 1;
        int result = 1;
        for (int i = 2; i <= n; i++) result *= i;
        return result;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    cout << "Factorial of " << n << " is " << sol.factorial(n) << endl;

    return 0;
}
