#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;

        unordered_map<char, int> pCount;   // count characters in p
        unordered_map<char, int> window;   // count characters in current window

        // Count characters in p
        for (char ch : p) pCount[ch]++;

        int left = 0, right = 0;           // two pointers
        int required = pCount.size();      // number of unique chars to match
        int formed = 0;                    // how many chars are fully matched

        while (right < s.size()) {
            char ch = s[right];
            window[ch]++;

            // Check if this char count matches in p
            if (pCount.count(ch) && window[ch] == pCount[ch]) {
                formed++;
            }

            // If window size > p.length(), move left pointer
            while (right - left + 1 > p.size()) {
                char leftChar = s[left];
                if (pCount.count(leftChar) && window[leftChar] == pCount[leftChar]) {
                    formed--;
                }
                window[leftChar]--;
                left++;
            }

            // If all characters match → it's an anagram
            if (formed == required) {
                result.push_back(left);
            }

            right++;
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s, p;

    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string p: ";
    cin >> p;

    vector<int> ans = sol.findAnagrams(s, p);

    cout << "Anagram starting indices: ";
    for (int idx : ans) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
