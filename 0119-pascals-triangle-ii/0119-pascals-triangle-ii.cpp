class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex+1;
             vector<vector<int>> ans(numRows);
       
    
          for(int i=0;i<numRows;i++){
            ans[i].push_back(1);
            for(int j=0;j<i-1;j++)
            {
               ans[i].push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            if(i>0)
            ans[i].push_back(1);
        }

    return ans[rowIndex];
    }
};