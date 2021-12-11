//
//Runtime 60 
//Memory Usage 36.1
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int preSum = 0, ans = 0 ;
        m[0] = 1;
        for(const int &num : nums){
            preSum += num;
            if(m.count(preSum - k))ans += m[preSum - k];
            ++m[preSum];
        }
        return ans;
    }
};
