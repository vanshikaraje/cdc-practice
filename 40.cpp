#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<long long> st;

        for (auto& token : arr) {
            // If current token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = 0;

                if (token == "+") res = a + b;
                else if (token == "-") res = a - b;
                else if (token == "*") res = a * b;
                else if (token == "/") {
                    // Floor division (handle negatives properly)
                    if ((a < 0) ^ (b < 0) && a % b != 0)
                        res = a / b - 1;
                    else
                        res = a / b;
                }
                else if (token == "^") res = pow(a, b);

                st.push(res);
            } 
            else {
                // Operand — convert string to integer
                st.push(stoi(token));
            }
        }

        return (int)st.top();
    }
};

// ---- Driver Code (For GFG + Local VS Code testing) ----
int main() {
    int n;
    cin >> n;  // number of elements
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution ob;
    cout << ob.evaluatePostfix(arr) << endl;

    return 0;
}
