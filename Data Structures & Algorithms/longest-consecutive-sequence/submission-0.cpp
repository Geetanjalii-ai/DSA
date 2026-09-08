class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int maxLen=0;

        unordered_set<int> s(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int currentNum=nums[i];
                int len=1;

                while(s.find(currentNum+1)!=s.end())
                {
                    currentNum++;
                    len++;
                }

                maxLen=max(maxLen,len);
            }
        }

        return maxLen;
        
    }
};
