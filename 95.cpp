#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> mapS(256, -1);
        vector<int> mapT(256, -1);

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (mapS[c1] == -1 && mapT[c2] == -1) {
                mapS[c1] = c2;
                mapT[c2] = c1;
            } 
            else if (mapS[c1] != c2 || mapT[c2] != c1) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s, t;
    cout << "Enter first string (s): ";
    cin >> s;
    cout << "Enter second string (t
