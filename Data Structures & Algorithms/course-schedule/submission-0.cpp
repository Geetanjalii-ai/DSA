class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {

        vector<vector<int>> adj(n);
        vector<int> inorder(n,0);
        for(int i=0;i<p.size();i++)
        {
            int u=p[i][0];
            int v=p[i][1];

            adj[u].push_back(v);
            inorder[v]++;
        }
        queue<int> q;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==0)
            {
                q.push(i);
                cnt++;
            }
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(int i : adj[node])
            {
                if(inorder[i]>0)
                {
                    inorder[i]--;
                }
                
                if(inorder[i]==0)
                {
                    q.push(i);
                    cnt++;
                }
            }
        }

        if(cnt!=n)
        {
            return false;
        }

        return true;
 
    }
};
