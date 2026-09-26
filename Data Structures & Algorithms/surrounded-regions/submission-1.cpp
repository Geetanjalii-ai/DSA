class Solution {
public:
    void solve(vector<vector<char>>& grid) {

        queue<pair<int,int>> q;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='O' && i<n && ( j==0 || j==m-1))
                {
                    q.push({i,j});
                    grid[i][j]='#';
                }
                else if(grid[i][j]=='O' && j<m && ( i==0 || i==n-1))
                {
                    q.push({i,j});
                    grid[i][j]='#';
                }
            }
        }

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            int x=it.first;
            int y=it.second;

            for(int d=0;d<4;d++)
            {
                int nx=x+dx[d];
                int ny=y+dy[d];

                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!='O')
                {
                    continue;
                }

                grid[nx][ny]='#';
                q.push({nx,ny});
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='O')
                {
                    grid[i][j]='X';
                }
                else if(grid[i][j]=='#')
                {
                    grid[i][j]='O';
                }
            }
        }
    
    }
};
