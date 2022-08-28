//dp
//Runtime 3
//Memory 8.6
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int l1, int l2) {
        vector<int> sum = nums;
        
        int n = nums.size();
        
        for(int i = 1; i < n; ++i)
            sum[i] += sum[i - 1];
        
        int res = sum[l1 + l2 - 1], s1 = sum[l2 - 1], s2 = sum[l1 - 1];
        
        for(int i = l1 + l2; i < n; ++i)
            s1 = max(s1, sum[i - l1] - sum[i - l1 - l2]), s2 = max(s2, sum[i - l2] - sum[i - l1 - l2]), res = max({res, s1 + sum[i] - sum[i - l1], s2 + sum[i] - sum[i - l2]});
        
        return res;
    }
};