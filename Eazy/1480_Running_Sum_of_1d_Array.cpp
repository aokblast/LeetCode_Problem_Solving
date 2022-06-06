//
//Runtime 3
//Memory Usage 8.5
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int cur = 0;
        for(const int num : nums){
            cur += num;
            res.push_back(cur);
        }
        return res;
    }
};