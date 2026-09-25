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
    int dfs(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }

        int l=dfs(root->left);
        int r=dfs(root->right);

        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {

        if(root==nullptr)
        {
            return true;
        }

        int hl=dfs(root->left);
        int hr=dfs(root->right);

        return abs(hl-hr)<=1 && isBalanced(root->left) && isBalanced(root->right);
        
    }
};
