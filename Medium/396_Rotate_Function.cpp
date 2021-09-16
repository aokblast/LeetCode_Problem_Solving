//
//Runtime 124
//Memory Usage 95.9
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, t = 0, ans = INT_MIN, n = nums.size();
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            t += nums[i] * i;
        }
        for(int i = 0; i < n; ++i){
            t += sum - n * nums[n - i - 1];
            ans = max(ans, t);
        }
        return ans;
    }
};
