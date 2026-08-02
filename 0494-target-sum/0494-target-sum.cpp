class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total < abs(t) || (total + t) % 2 != 0)
            return 0;
        t = (total + t) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(t + 1, 0));

    for(int i = 0;i<n;i++){
        dp[i][0] =1;
    }

    if (nums[0] != 0 && nums[0] <= t) {
            dp[0][nums[0]] = 1;
        }
        int z = (nums[0]==0?1:0);
        for (int i = 1; i < n; i++) {
            if(nums[i] == 0){
                z++;
                dp[i] = dp[i-1];
                continue;
            }
            for (int j = 1; j <= t; j++) {
                if (nums[i] <= j) {
                    dp[i][j] = dp[i-1][j - nums[i]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n - 1][t]*(1<<z);
    }
};