#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node (LeetCode provides this automatically)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Your LeetCode solution (works same here)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false; // Base case: empty tree
        
        // If it's a leaf node, check if the sum equals targetSum
        if (!root->left && !root->right)
            return (targetSum == root->val);
        
        // Recursive check for left or right subtree
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

// Main function for testing
int main() {
    // Construct the example tree: [5,4,8,11,null,13,4,7,2,null,null,null,1]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    Solution sol;
    cout << (sol.hasPathSum(root, targetSum) ? "true" : "false") << endl;

    return 0;
}
