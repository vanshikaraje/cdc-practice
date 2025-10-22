#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;  // store all combinations

    void backtrack(int start, int n, int k, vector<int>& current) {
        // base case: if current combination has k numbers
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // try all numbers from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            current.push_back(i);           // choose
            backtrack(i + 1, n, k, current); // explore
            current.pop_back();             // un-choose
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        backtrack(1, n, k, current);
        return result;
    }
};
