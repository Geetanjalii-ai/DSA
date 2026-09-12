class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        vector<int> ans(queries.size(),-1);

        vector<pair<int,int>> qr;
        for(int i=0;i<queries.size();i++)
        {
            qr.push_back({queries[i],i});
        }

        sort(qr.begin(),qr.end());
        sort(intervals.begin(),intervals.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        int j=0;
        for(int i=0;i<qr.size();i++)
        {
            int q=qr[i].first;

            while(j<intervals.size() && intervals[j][0]<=q)
            {
                int start=intervals[j][0];
                int end=intervals[j][1];
                pq.push({end-start+1,end});
                j++;
            }

            while(!pq.empty() && pq.top().second<q)
            {
                pq.pop();
            }

            if(!pq.empty())
            {
                int idx=qr[i].second;
                ans[idx]=pq.top().first;
            }

        }
        return ans;
        
    }
};
