class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int target = total/2;
        if(target*2 != total) return false;

        int n = nums.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));

        for(int i = 0;i<n;i++){
            dp[i][0]=true;
        }

        for(int i = 1;i<n;i++){
            if(nums[i] == 0){
                dp[i]=dp[i-1];
                continue;
            }

            for(int j = 1;j<=target;j++){
                if(nums[i]<=j){
                    dp[i][j] = dp[i-1][j-nums[i]] || dp[i-1][j];
                }else{
                    dp[i][j] =  dp[i-1][j];

                }
            }
        }



        return dp[n-1][target];


 
    }
};