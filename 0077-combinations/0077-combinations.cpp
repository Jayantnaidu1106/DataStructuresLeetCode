class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,int k,int n,vector<int> &l){
        if(l.size() == k){
            ans.push_back(l);
            return;
        }

           
        for(int j = i;j<=n;j++){
            l.push_back(j);
            solve(j+1,k,n,l);
            l.pop_back();
        }
           
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> l;

        solve(1,k,n,l);
        return ans;
    }
};