#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int curr = 1; // start reading numbers from 1

        for (int i = 0; i < target.size(); i++) {
            // Push numbers until we reach target[i]
            while (curr < target[i]) {
                result.push_back("Push");
                result.push_back("Pop"); // since it's not in target, we remove it
                curr++;
            }
            // Now push the target element
            result.push_back("Push");
            curr++;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> target = {1, 3};
    int n = 3;
    vector<string> ans = sol.buildArray(target, n);

    for (auto &s : ans)
        cout << s << " ";
    cout << endl;
    return 0;
}
