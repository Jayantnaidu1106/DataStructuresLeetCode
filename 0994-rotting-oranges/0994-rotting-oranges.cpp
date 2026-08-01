class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int iy[4] = {0, 1, 0, -1};
        int ix[4] = {-1, 0, 1, 0};
        queue < pair<int, int>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        int l = 0;
        while (!q.empty()) {
            int s = q.size();
            
           
            for (int i = 0; i < s; i++) {
                auto idx = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = idx.first + ix[j];
                    int ny = idx.second + iy[j];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                        !vis[nx][ny] && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
                
            }
             l++;
        }

         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)return -1;
                    
            }
        }
        return l==0?0:l-1;
    }
};