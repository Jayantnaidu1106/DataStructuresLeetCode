class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<int> krow = {-1,0,1,0};
    vector<int> kcol = {0,-1,0,1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));

        dist[0][0] = grid[0][0];

        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({grid[0][0],{0,0}});
        int mtime = 0;
        while(!pq.empty()){
            auto [time ,rc] = pq.top();
            int r = rc.first;
            int c = rc.second;

            pq.pop();
            if(time > dist[r][c]) continue;
            mtime = max(mtime,time);
            if(r == n- 1 && c == m -1) return mtime;

            for(int i = 0;i < 4;i++){
                int nr = r + krow[i];
                int nc = c + kcol[i];
                if(nr>= 0 && nr < n && nc >= 0 && nc < m){
                      int gt = max(grid[nr][nc],time);
                if(gt < dist[nr][nc]){
                    dist[nr][nc] = gt;
                    pq.push({gt,{nr,nc}});
                }
                }
            }
        }
        return -1;
    }
};