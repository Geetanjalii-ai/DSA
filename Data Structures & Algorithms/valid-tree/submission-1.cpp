class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int> &vis,int parent,int n)
    {
        vis[n]=1;

        for(int node : adj[n])
        {
            if(vis[node]==1 && node!=parent)
            {
                return false;
            }

            if(vis[node]==0)
            {
                if(dfs(adj,vis,n,node)==false)
                {
                    return false;
                }
            }
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<int> vis(n,0);
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(adj,vis,-1,i)==false)
                {
                    return false;
                }
                cnt++;
            }
        }

        if(cnt>1)
        {
            return false;
        }
        
        return true;
    }
};
