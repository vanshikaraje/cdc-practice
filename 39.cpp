#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;

        // Step 2: Use a max-heap to sort by frequency
        priority_queue<pair<int, char>> pq;
        for (auto &p : freq) {
            pq.push({p.second, p.first});  // {frequency, character}
        }

        // Step 3: Build the result string
        string result = "";
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            result += string(count, ch);  // append char 'count' times
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter string: ";
    cin >> s;

    string ans = sol.frequencySort(s);
    cout << "Sorted by frequency: " << ans << endl;

    return 0;
}
