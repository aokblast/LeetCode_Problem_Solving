//Binary Search
//Runtime 13
//Memory Usage 13.8

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 1; i < n; ++i) 
            nums[i] += nums[i - 1];

        vector<int> res;

        for(const int q : queries) 
            res.push_back(
                upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        
        
        return res;
    }
};