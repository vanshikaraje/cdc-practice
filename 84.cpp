#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal)
            return false;
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};

int main() {
    // Example 1: Valid BST [2,1,3]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    Solution sol;
    cout << (sol.isValidBST(root1) ? "true" : "false") << endl;

    // Example 2: Invalid BST [5,1,4,null,null,3,6]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    cout << (sol.isValidBST(root2) ? "true" : "false") << endl;

    return 0;
}
