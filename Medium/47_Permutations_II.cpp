//next permutation
//Runtime 4
//Memory Usage 8.2

class Solution {
public:
    map<int, int> m;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(nums);
        
        int size = nums.size();
        int total = 1;
        for(int i = 2; i <= size; ++i) total *= i;
        for(int i = 0; i < size; ++i) ++m[nums[i]];
        for(auto iter = m.begin(); iter != m.end(); ++iter) {
            if(iter->second >= 2)for(int i = 1; i <= iter->second; ++i) total /= i;
        }
        while(--total){
            next_permutation(nums.begin(), nums.end());
            result.push_back(nums);
        }
        return result;
    }
};
