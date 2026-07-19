class Solution {
public:
    string smallestSubsequence(string s) {
     string ans="";
     vector<int> al(26,-1);
     vector<bool> vis(26,false);
     int n = s.size();
     for(int i =0;i<n;i++){
        al[s[i] - 'a'] = i;
     }
     for(int i = 0;i<n;i++){
        if(ans.size() == 0 || !vis[s[i] - 'a'] && ans.back() < s[i]){
            ans.push_back(s[i]);
            vis[s[i] - 'a'] = true;
            continue;
        }
        while(ans.size()>0 && ans.back()>s[i] &&!vis[s[i]-'a'] && al[ans.back() - 'a']>i){
            vis[ans.back() - 'a'] = false;
            ans.pop_back();
        }
      if(!vis[s[i]-'a']){

        ans.push_back(s[i]);
        vis[s[i]-'a'] = true;
      }

    
     }


     return ans;
    }
};