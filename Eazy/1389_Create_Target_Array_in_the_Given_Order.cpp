//
//Runtime 8
//Memory Usage 8.5
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        
        vector<int> res;

        for(int i = 0; i < n; ++i) 
            res.insert(res.begin() + index[i], nums[i]);
        
        return res;
    }
};