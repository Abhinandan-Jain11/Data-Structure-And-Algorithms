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
    int pathSum(TreeNode *root, int &sum){
        if(!root) return 0;
        int L = max(0,pathSum(root->left,sum));
        int R = max(0,pathSum(root->right,sum));
        sum = max(sum, root->val+L+R);
        
        return root->val + max(L,R);
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        pathSum(root,sum);
        return sum;
    }
};