class Solution {
public:
    int trap(vector<int>& heights) {

        int n=heights.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0]=heights[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],heights[i]);
        }

        suffix[n-1]=heights[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],heights[i]);
        }

        int tot=0;

        for(int i=0;i<n;i++)
        {
            tot+=min(prefix[i],suffix[i])-heights[i];
        }

        return tot;
    }
};
