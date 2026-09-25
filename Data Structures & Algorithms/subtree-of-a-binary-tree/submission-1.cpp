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
   

    bool isSame(TreeNode* ro,TreeNode* sub)
    {
        if(ro==nullptr && sub==nullptr)
        {
            return true;
        }

        if(ro==nullptr || sub==nullptr)
        {
            return false;
        }

        return ro->val==sub->val && isSame(ro->left,sub->left) && isSame(ro->right,sub->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root==nullptr)
        {
            return false;
        }

        if(isSame(root,subRoot))
        {
            return true;
        }

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};
