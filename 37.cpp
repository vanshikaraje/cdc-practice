#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);
        vector<bool> inStack(26, false);
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
            lastIndex[s[i] - 'a'] = i;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (inStack[c - 'a']) continue;

            while (!st.empty() && c < st.top() && i < lastIndex[st.top() - 'a']) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[c - 'a'] = true;
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter string: ";
    cin >> s;

    string ans = sol.removeDuplicateLetters(s);
    cout << "Result: " << ans << endl;

    return 0;
}
