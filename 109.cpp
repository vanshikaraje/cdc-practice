class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        backtrack(n, 0, 0, cur, ans);
        return ans;
    }
private:
    // open = number of '(' used so far
    // close = number of ')' used so far
    void backtrack(int n, int open, int close, string &cur, vector<string> &ans) {
        if ((int)cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }
        // try to add '(' if we still can
        if (open < n) {
            cur.push_back('(');
            backtrack(n, open + 1, close, cur, ans);
            cur.pop_back();
        }
        // try to add ')' only if it won't make string invalid
        if (close < open) {
            cur.push_back(')');
            backtrack(n, open, close + 1, cur, ans);
            cur.pop_back();
        }
    }
};
