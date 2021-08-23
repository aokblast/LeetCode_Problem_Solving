//dfs
//Runtime 4
//Memory Usage 10.6
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
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            tmp.push_back(candidates[i]);
            dfs(candidates, sum + candidates[i], i + 1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        tar = target;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0);
        return result;
    }
};
