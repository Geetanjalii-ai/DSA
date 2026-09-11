class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;

        int n=t.size();
        for(int i=0;i<n;i++)
        {
            mpp2[t[i]]++;
        }
        int c=0;
        int minL=INT_MAX;
        int left=0;
        int start=-1;
        for(int i=0;i<s.size();i++)
        {
            mpp1[s[i]]++;
            if(mpp2.find(s[i])!=mpp2.end() && mpp2[s[i]]>=mpp1[s[i]])
            {
                c++;
            }

            while(c==n)
            {
                if((i-left+1)<minL)
                {
                    minL=i-left+1;
                    start=left;
                }

                mpp1[s[left]]--;
                if(mpp1[s[left]]==0)
                {
                    mpp1.erase(s[left]);
                }
                if(mpp2.find(s[left])!=mpp2.end() && mpp1[s[left]]<mpp2[s[left]])
                {
                    c--;
                }

                left++;
            }
        }

        if(start==-1)
        {
            return "";
        }


        return s.substr(start,minL);
        
    }
};
