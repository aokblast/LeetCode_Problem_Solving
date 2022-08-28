//
//Runtime 12
//Memory Usage 13.9

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> res(n);
        
        int cur = 0;
        
        for(int i = 0; i < n; ++i){
            cur = (cur << 1 | nums[i]) % 5;
            res[i] = cur == 0;
        }
        return res;
    }
};