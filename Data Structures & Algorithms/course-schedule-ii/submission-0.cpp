class Solution {
public:
     bool dfs(vector<vector<int>> &adj,vector<int> &vis,int n,stack<int> &st)
    {
        vis[n]=1;

        for(int node:adj[n])
        {
            if(vis[node]==1)
            {
                return false;
            }
            if(vis[node]==0)
            {
                if(dfs(adj,vis,node,st)==false)
                {
                    return false;
                }
            }
        }

        vis[n]=2;
        st.push(n);
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {

        vector<int> vis(n,0);

        vector<vector<int>> adj(n);

        for(int i=0;i<p.size();i++)
        {
            int u=p[i][0];
            int v=p[i][1];

            adj[u].push_back(v);
        }

        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(adj,vis,i,st)==false)
                {
                    return {};
                }
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;     
    }
};
