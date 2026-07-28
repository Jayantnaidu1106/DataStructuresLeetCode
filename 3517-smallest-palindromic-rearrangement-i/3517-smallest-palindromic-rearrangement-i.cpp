class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        sort(s.begin(),s.begin()+n/2);
        if(n &1)
            sort(s.begin()+n/2+1,s.end(),greater<char>());
        else
            sort(s.begin()+n/2,s.end(),greater<char>());

        return s;
    }
};