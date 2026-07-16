class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0;
        int n = arr.size();
        if (k == n) return arr;
        
       
        while (i < n && arr[i] < x) {
            i++;
        }
   
        if (i == n) {
            i--; 
        } else if (i > 0 && abs(arr[i] - x) >= abs(arr[i - 1] - x)) {
            i--;
        }
        
        vector<int> ans;
        int l = i - 1;
        int r = i + 1;
        
        ans.push_back(arr[i]);
        k--;
        
        while (k > 0) {
            if (l < 0) {
                ans.push_back(arr[r++]);
            } else if (r >= n) {
                ans.push_back(arr[l--]);
            } else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
              
                ans.push_back(arr[l--]);
            } else {
                ans.push_back(arr[r++]);
            }
            k--;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};