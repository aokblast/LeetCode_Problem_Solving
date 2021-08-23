/dfs
//Runtime 0
//Memory Usage 7.6
class Solution {
public:
    vector<vector<int>> result;
    int size;
    void dfs(vector<int> &nums, vector<int> &tmp, int layer, int start){
        result.push_back(tmp);
        
        if(layer == size) return;
        for(int i = start; i < size; ++i){
            tmp.push_back(nums[i]);
            dfs(nums, tmp, layer + 1, i  +1);
            tmp.pop_back();
            while(i < size  - 1 && nums[i] == nums[i + 1]  ) ++i;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        size = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        dfs(nums, tmp, 0, 0);
        return result;
        
    }
};
