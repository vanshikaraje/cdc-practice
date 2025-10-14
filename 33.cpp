#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int original = num;

        while (num > 0) {
            int digit = num % 10;
            if (digit != 0 && original % digit == 0) count++;
            num /= 10;
        }

        return count;
    }
};

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    Solution sol;
    int result = sol.countDigits(num);

    cout << "Number of digits that divide " << num << ": " << result << endl;

    return 0;
}
