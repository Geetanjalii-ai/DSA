class Solution {
public:
    int largestRectangleArea(vector<int>& h) {

        int n=h.size();

        vector<int> nextS(n,n);
        vector<int> prevS(n,-1);

        stack<int> st1,st2;
        for(int i=n-1;i>=0;i--)
        {
            while(!st1.empty() && h[st1.top()]>=h[i])
            {
                st1.pop();
            }

            if(!st1.empty())
            {
                nextS[i]=st1.top();
            }

            st1.push(i);
        }

        for(int i=0;i<n;i++)
        {
            while(!st2.empty() && h[st2.top()]>=h[i])
            {
                st2.pop();
            }

            if(!st2.empty())
            {
                prevS[i]=st2.top();
            }

            st2.push(i);
        }

        int maxArea=0;

        for(int i=0;i<h.size();i++)
        {
            int he=h[i];
            int wid=nextS[i]-prevS[i]-1;
            int area=he*wid;
            maxArea=max(maxArea,area);

        }

        return maxArea;
    }
};
