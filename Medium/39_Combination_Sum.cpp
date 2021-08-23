//dfs
//Runtime 4
//Memory Usage 11.1

class Solution {
public:
    vector<vector<int>>result;
    int tar;
    vector<int> tmp;
    void dfs(vector<int> &candidates, int sum, int start){
        if(sum == tar){
            result.push_back(tmp);
            return;
        }
        for(int i = start; i < candidates.size(); ++i){
            if(sum + candidates[i] > tar)break;
            tmp.push_back(candidates[i]);
            dfs(candidates, sum + candidates[i], i);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        tar = target;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0);
        return result;
    }
};
