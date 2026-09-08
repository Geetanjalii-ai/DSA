class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string,int> mpp;
        for(int i=0;i<strs.size();i++)
        {
            string key=strs[i];

            sort(key.begin(),key.end());

            if(mpp.find(key)==mpp.end())
            {
                mpp[key]=ans.size();
                ans.push_back({});
            }

            ans[mpp[key]].push_back(strs[i]);
        }

        return ans;

    }
};
