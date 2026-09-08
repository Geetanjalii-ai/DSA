class Solution {
public:
   string a="gEeTa";
    string encode(vector<string>& strs) {

        string en="";

        for(int i=0;i<strs.size();i++)
        {
            en+=strs[i]+a;
        }

        return en;

    }

    vector<string> decode(string s) {

        vector<string> ans;
        string str="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='g' && i+5<=s.size())
            {
                string temp=s.substr(i,5);
                if(temp==a)
                {
                    ans.push_back(str);
                    str="";
                    i=i+4;
                    continue;
                }
            }

            str+=s[i];
        }

        return ans;

    }
};
