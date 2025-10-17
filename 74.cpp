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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans; // empty tree check

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Step 1: Go as left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Step 2: Process the node
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            // Step 3: Move to the right subtree
            curr = curr->right;
        }

        return ans;
    }
};

// ---------------- Testing in VS Code ----------------
int main() {
    // Constructing a binary tree:
    //        1
    //         \
    //          2
    //         /
    //        3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
