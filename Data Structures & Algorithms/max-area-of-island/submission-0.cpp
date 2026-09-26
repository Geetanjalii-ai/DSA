class Solution {
public:
    int cnt=0;
    void dfs(vector<vector<int>> &grid,int i,int j,int &cnt)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
        {
            return;
        }

        cnt++;
        grid[i][j]=0;
        dfs(grid,i+1,j,cnt);
        dfs(grid,i-1,j,cnt);
        dfs(grid,i,j+1,cnt);
        dfs(grid,i,j-1,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxA=0;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cnt=0;
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,cnt);
                }
                maxA=max(maxA,cnt);
            }
        }

        return maxA;
        
    }
};
