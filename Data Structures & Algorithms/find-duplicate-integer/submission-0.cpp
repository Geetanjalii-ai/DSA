class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        vector<int> vis(nums.size()+1,0);
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(vis[nums[i]]==1)
            {
                ans=nums[i];
                break;
            }
            vis[nums[i]]=1;
        }

        return ans;
        
    }
};
