#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ---------------- Solution Class ----------------
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;       // both null
        if (!p || !q) return false;      // one null
        if (p->val != q->val) return false; // values differ

        // recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// ---------------- Testing in VS Code ----------------
int main() {
    TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* root2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    Solution sol;
    bool same = sol.isSameTree(root1, root2);

    cout << (same ? "Trees are the same" : "Trees are different") << endl;

    return 0;
}
