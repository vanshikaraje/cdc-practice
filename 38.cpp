#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> freq;
        int n = s.size();
        int maxCount = 0;

        for (int i = 0; i <= n - minSize; i++) {
            string sub = s.substr(i, minSize);
            unordered_set<char> uniqueChars(sub.begin(), sub.end());
            if (uniqueChars.size() <= maxLetters) {
                freq[sub]++;
                maxCount = max(maxCount, freq[sub]);
            }
        }

        return maxCount;
    }
};

int main() {
    Solution sol;
    string s;
    int maxLetters, minSize, maxSize;

    cout << "Enter string: ";
    cin >> s;
    cout << "Enter maxLetters, minSize, maxSize: ";
    cin >> maxLetters >> minSize >> maxSize;

    int ans = sol.maxFreq(s, maxLetters, minSize, maxSize);
    cout << "Maximum occurrences: " << ans << endl;

    return 0;
}
