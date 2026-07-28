class Solution {
public:
    vector<vector<int>> ans;
    bool valid(vector<int> &l){
        int n = l.size();
        if(n<=1)return false;
        for(int i = 1;i < n;i++){
            if(l[i] < l[i-1]){
                return false;
            }
        }
        return true;
    }
    void solve(int i,int n,vector<int> &nums,vector<int> &l){
        if(i == n){
            if(valid(l)){
                 ans.push_back(l);  
                 return;   
            }
                return;
        }

        // if(nums[i] < l.back()){
        //     l.push_back(nums[i]);
        //     solve(i + 1,n,nums,l);
        // }
        l.push_back(nums[i]);
        solve(i + 1,n,nums,l);
        l.pop_back();
        solve(i+1,n,nums,l);
           
    }
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        vector<int> l;
        int n = nums.size();
        solve(0,n,nums,l);
        set<vector<int>> a(ans.begin(),ans.end());
        vector<vector<int>> aa(a.begin(),a.end());
        return aa;
    }
};