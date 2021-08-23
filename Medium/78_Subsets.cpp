//DFS
//Runtime 0
//Memory Usage 7.2
class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    int size;
    void dfs(vector<int> & nums, int start){
        result.push_back(tmp);
        if(start == size) return;
        for(int i = start; i < size; ++i){
            tmp.push_back(nums[i]);
            dfs(nums, i  + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();
        dfs(nums, 0);
        return result;
    }
};
