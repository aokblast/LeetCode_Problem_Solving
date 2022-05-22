//greedy
//Runtime 310
//Memory Usage 98.2
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int mx[n], mn[n];
        int a = INT_MIN, b = INT_MAX;
        for(int i = 0; i < n; ++i){
            a = max(a, nums[i]), b = min(b,nums[n - 1 - i]);
            mx[i] = a, mn[n - 1 - i] = b;
        }
        for(int i = 0; i < n - 1; ++i){
        
            if(mx[i] <= mn[i + 1])
                return i + 1;
        }
        return 0;
    }
};