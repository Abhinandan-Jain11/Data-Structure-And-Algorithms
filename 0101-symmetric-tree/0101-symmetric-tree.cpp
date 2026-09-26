/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* r1, TreeNode* r2) {
        // Both are NULL
        if (!r1 && !r2)
            return true;

        // One is NULL
        if (!r1 || !r2)
            return false;

        // Values different
        if (r1->val != r2->val)
            return false;

        // Check mirror pairs
        return check(r1->left, r2->right) && check(r1->right, r2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->left, root->right);
    }
};