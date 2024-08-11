class Solution {
private:
    void bfs(int i,int j,vector<vector<int>>&newGrid,vector<vector<int>>&vis)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row>0 && newGrid[row-1][col]==0 && vis[row-1][col]==0)
            {
                vis[row-1][col]=1;
                q.push({row-1,col});
            }
            if(row<newGrid.size()-1 && newGrid[row+1][col]==0 && vis[row+1][col]==0)
            {
                vis[row+1][col]=1;
                q.push({row+1,col});
            }
            if(col>0 && newGrid[row][col-1]==0 && vis[row][col-1]==0)
            {
                vis[row][col-1]=1;
                q.push({row,col-1});
            }
             if(col<newGrid[0].size()-1 && newGrid[row][col+1]==0 && vis[row][col+1]==0)
            {
                vis[row][col+1]=1;
                q.push({row,col+1});
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int res=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>newGrid(3*n,vector<int>(3*m,0));  
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='/')
                {
                    newGrid[3*i][3*j+2]=1;
                    newGrid[3*i+1][3*j+1]=1;
                    newGrid[3*i+2][3*j]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    newGrid[3*i][3*j]=1;
                    newGrid[3*i+1][3*j+1]=1;
                    newGrid[3*i+2][3*j+2]=1;
                }
            }
        } 
        vector<vector<int>>vis(3*n,vector<int>(3*m,0));  
        for(int i=0;i<newGrid.size();i++)
        {
            for(int j=0;j<newGrid[0].size();j++)
            {
                if(newGrid[i][j]==0 && vis[i][j]==0)
                {
                    res++;
                    bfs(i,j,newGrid,vis);
                }
            }
        }

        return res;
    }
};