class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        vector<int> arr(n + 2,0);
        for(auto &e : b){
            arr[e[0]] +=e[2];
            arr[e[1] + 1] -= e[2];
        }
        vector<int> ans;
        int currS = 0;
        for(int i = 1;i <= n;i++){
            currS += arr[i];
            ans.push_back(currS);
        }
        return ans;
    }
};