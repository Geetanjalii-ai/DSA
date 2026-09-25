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
    int kthSmallest(TreeNode* root, int k) {

        if(root==nullptr)
        {
            return 0;
        }

        stack<TreeNode*> st;
        TreeNode* curr=root;
        int x=1;
        int ans=-1;
        while(curr!=nullptr || !st.empty())
        {
            while(curr!=nullptr)
            {
                st.push(curr);
                curr=curr->left;
            }

            curr=st.top();
            st.pop();

            if(x==k)
            {
                ans=curr->val;
                break;
            }
            x++;

            curr=curr->right;
        }

        return ans;
        
    }
};
