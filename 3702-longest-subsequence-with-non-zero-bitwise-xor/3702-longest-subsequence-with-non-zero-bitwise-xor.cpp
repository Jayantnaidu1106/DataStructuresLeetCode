class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool isall = true;
        int x = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            x^= nums[i];
            if(nums[i]!=0){
                isall = false;
            }
        }


        if(x != 0)return n;
        else if(isall)return 0;

    return n-1;
    }
};