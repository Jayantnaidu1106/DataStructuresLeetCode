class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        int maxi = 0;
        int n = nums.size();
        if(n == 1)return 0;
        vector<int> pre(n);

        for(int i = 0;i<n;i++){
            maxi = max(nums[i],maxi);
            pre[i] = gcd(nums[i],maxi);
        }
        sort(pre.begin(),pre.end());
        int i = 0,j=n-1;

        long long sum = 0;
        while(i<j){
            sum+=gcd(pre[i++],pre[j--]);
        }

        return sum;
    }
};