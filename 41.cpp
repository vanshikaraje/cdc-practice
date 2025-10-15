#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If stack is empty, invalid string
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check for matching pairs
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack is empty → all brackets matched
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s; // input from user (like "()[]{}")
    cout << (sol.isValid(s) ? "true" : "false") << endl;
    return 0;
}
