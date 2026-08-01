class Solution {
public:
    int n,m;
     int iy[4] = {0,1,0,-1};
    int ix[4] = {-1,0,1,0};
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int x,int y){
        if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || !grid[x][y]) return 0;
        vis[x][y] = true;
        int le = dfs(grid,vis,x,y-1);
         int ri = dfs(grid,vis,x,y+1);
          int t = dfs(grid,vis,x -1,y);
           int d = dfs(grid,vis,x + 1,y);

        return 1 + le + ri + t + d;
    }
       

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));


        int maxi = 0;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    maxi = max(maxi,dfs(grid,vis,i,j));
                }
            }
        }


        return maxi;
    }
};