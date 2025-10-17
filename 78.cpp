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


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);
        return 1 + max(leftH, rightH);
    }
};

int main() {
  
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution sol;
    int depth = sol.maxDepth(root);

    cout << "Maximum Depth: " << depth << endl;

    return 0;
}
