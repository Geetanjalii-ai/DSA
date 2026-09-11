class Solution {
public:
    bool isPalindrome(string s) {

        string word="";

        for(int i=0;i<s.size();i++)
        {
            if(isalnum(s[i]))
            {
                word+=tolower(s[i]);
            }
        }

        int l=0;
        int r=word.size()-1;

        while(l<=r)
        {
            if(word[l]!=word[r])
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};
