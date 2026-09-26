class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        //int INF=INT_MAX;
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
       // vector<vector<int>> vis(n,(vector<int>(m,0)));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                auto it=q.front();
                q.pop();

                int x=it.first;
                int y=it.second;

                for(int d=0;d<4;d++)
                {
                    int nx=x+dx[d];
                    int ny=y+dy[d];

                    if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=INT_MAX)
                    {
                        continue;
                    }

                    grid[nx][ny]=grid[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        
    }
};
