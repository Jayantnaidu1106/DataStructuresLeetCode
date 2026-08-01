class Solution {
public:
  
    int solvep1(vector<int> &nums,int l,int r,bool turn){
        if(l>r)return 0;
        if(turn == false){
            return min(solvep1(nums,l + 1,r,!turn),solvep1(nums,l,r -1,!turn));
        }

        return max(nums[l] + solvep1(nums,l + 1,r,!turn),nums[r] + solvep1(nums,l,r -1,!turn));
    }
    bool predictTheWinner(vector<int>& nums) {
       int n = nums.size();

      int p1 = solvep1(nums,0,n-1,true);
        int s = accumulate(nums.begin(),nums.end(),0);
        int p2 = s - p1;
       return p1>=p2; 
    }
};