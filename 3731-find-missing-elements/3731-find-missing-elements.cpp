class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i-1]+1 == nums[i])continue;
            int count = nums[i-1];
        while(  count+1 != nums[i]){
            ans.push_back(count+1);
            count++;
            }
        }

        return ans;
    }
};