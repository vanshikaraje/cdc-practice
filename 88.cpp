#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        fill(hash, hash + 256, -1);

        int n = s.size();
        int l = 0, r = 0, maxLen = 0;

        while (r < n) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
            maxLen = max(maxLen, r - l + 1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Length of longest substring without repeating characters: "
         << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
