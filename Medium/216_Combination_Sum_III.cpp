//dfs
//Runtime 0
//Memory Usage 6.5
class Solution {
public:
    vector<vector<int>> ans;
    int lim;
    int ls;
    void dfs(int start, int sum, int size, vector<int> &tmp){
        if(size == ls){
            if(sum == lim) ans.push_back(tmp);
            return;
        }
        for(int i = start; i <= 9; ++i){
            tmp.push_back(i);
            dfs(i + 1 , sum + i, size + 1, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        lim = n, ls = k;
        dfs(1, 0, 0, tmp);
        return ans;    
    }
};
