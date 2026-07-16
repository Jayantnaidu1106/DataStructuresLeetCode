class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> m;

        for(int i : nums){
            m[i] = 1;
        }

        int s = 1;
        int e = *max_element(nums.begin(),nums.end());

        for(int i = s;i<=e;i++){
            if(m.find(i) == m.end())return i;
        }


        return max(s,e+1);
        
    }
};