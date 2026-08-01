class Solution {
public:
    void dfs(vector<vector<int>>& r,vector<bool>& vis,int i){
        vis[i]=true;
        for(auto idx : r[i]){
            if(!vis[idx])dfs(r,vis,idx);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& r) {
    int n = r.size();
    vector<bool> vis(n);

        dfs(r,vis,0);
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }


        return true;
    }
};