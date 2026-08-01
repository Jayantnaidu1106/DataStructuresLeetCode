class Solution {
public:
    int n,m;
     int iy[4] = {0,1,0,-1};
    int ix[4] = {-1,0,1,0};
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int x,int y){
        vis[x][y] = true;
          int ans = 1;
        for(int i = 0;i<4;i++){
            int nx = x + ix[i];
           int ny = y + iy[i];

            if(nx>=0 && ny>=0 && nx<n && ny <m){
            if(!vis[nx][ny] && grid[nx][ny])
             ans += dfs(grid,vis,nx,ny);
            }
        }


        return ans;
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