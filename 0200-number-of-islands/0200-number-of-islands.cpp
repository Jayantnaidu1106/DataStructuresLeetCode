class Solution {
public:
    int n;
    int m;
    int iy[4] = {0,1,0,-1};
    int ix[4] = {-1,0,1,0};
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int x,int y){
       

        vis[x][y] = true;


        for(int i = 0;i<4;i++){
           int nx = x + ix[i];
           int ny = y + iy[i];


            if(nx>=0 && ny>=0 && nx<n && ny <m){
                if(!vis[nx][ny] && grid[nx][ny] == '1'){
                    dfs(grid,vis,nx,ny);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }


        return count;
    }
};