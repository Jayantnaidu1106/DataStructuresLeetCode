class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n+2,0);

        for(int i = n-1;i>=0;i--){
            if(s[i]==')')continue;

            if(i+1<n && s[i+1] == ')'){
                dp[i] = 2 + dp[i+2];
            }else{
                int x = dp[i+1];
                int idx = i+x+1;

                if(idx<n && s[idx]==')'){
                    dp[i] = 2 + x + dp[idx+1];
                }
            }


        }
            return *max_element(dp.begin(),dp.end());
       
    }
};