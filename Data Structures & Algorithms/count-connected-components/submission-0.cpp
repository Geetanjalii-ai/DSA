class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int> &vis,int n)
    {
        vis[n]=1;

        for(int node : adj[n])
        {
            if(vis[node]==0)
            {
                dfs(adj,vis,node);
            }
        }

        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {

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
                dfs(adj,vis,i);
                cnt++;
            }
        }

        return cnt;
    }
};
