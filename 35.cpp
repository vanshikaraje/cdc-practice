#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper to reverse a number
    int reverseNumber(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    // Function GfG driver expects
    int reverseExponentiation(int n) {
        int rev = reverseNumber(n);
        int result = 1;
        for (int i = 0; i < rev; i++) {
            result *= n;
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;

    Solution ob;
    int ans = ob.reverseExponentiation(n);
    cout << ans << endl;

    return 0;
}
