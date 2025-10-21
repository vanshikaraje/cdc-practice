#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Check if n is a power of 2 using bit manipulation
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (sol.isPowerOfTwo(n))
        cout << n << " is a power of two ✅" << endl;
    else
        cout << n << " is NOT a power of two ❌" << endl;

    return 0;
}
