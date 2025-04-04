/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int d, int& dmax) {
        if (root != nullptr) {
            dmax = max(dmax, d);

            dfs(root->left, d + 1, dmax);
            dfs(root->right, d + 1, dmax);
        }
    }

    bool postOrder(TreeNode* root, TreeNode** ans, int d, int& dmax) {
        if (root != nullptr) {
            bool b1 = false;
            bool b2 = false;

            if (postOrder(root->left, ans, d + 1, dmax))
                b1 = true;
            if (postOrder(root->right, ans, d + 1, dmax))
                b2 = true;

            if (b1 && b2)
                *ans = root;
            return b1 || b2;
        } else {
            if (d == dmax + 1)
                return true;
            else
                return false;
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int dmax = 0;
        dfs(root, 0, dmax);

        TreeNode* ans = nullptr;
        postOrder(root, &ans, 0, dmax);

        return ans;
    }
};
