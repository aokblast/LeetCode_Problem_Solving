//dp
//Runtime 0
//Memory Usage 6.5

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = vector<int>(1);
        ans[0][0] = 1;
        for(int i = 1; i  < numRows; ++i){
            ans[i] = vector<int>(1);
            ans[i][0] = 1;
            for(int j = 1;j < i; ++j){
                ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }
            ans[i].push_back(1);
            
        }
        return ans;
    }
};
