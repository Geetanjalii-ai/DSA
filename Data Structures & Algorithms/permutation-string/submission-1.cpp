class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size()>s2.size())
        {
            return false;
        }
        int n=s1.size();
        sort(s1.begin(),s1.end());

        int l=0;
        while(l<=(s2.size()-n))
        {
            string str=s2.substr(l,n);

            sort(str.begin(),str.end());

            if(str==s1)
            {
                return true;
            }

            l++;
        }

        return false;
        
    }
};
