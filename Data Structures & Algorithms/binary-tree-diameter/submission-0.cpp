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
    int longest=INT_MIN;
    int dfs(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }

        int left=dfs(root->left);
        int right=dfs(root->right);

        longest=max(longest,left+right+1);

        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {

        if(root==nullptr)
        {
            return 0;
        }

        int dia=dfs(root);

        return (longest==INT_MIN) ? INT_MIN : longest-1;
        
    }
};
