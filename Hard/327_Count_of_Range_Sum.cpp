//merge
//Runtime 746
//Memory Usage 189.4
class Solution {
public:
    long long preSum[100005] = {0};
    int low , upp;
    int jisuan(vector<int> &nums, int left, int right){
        if((right - left) <= 1) return 0;
        int mid = (left + right) >> 1, ans = jisuan(nums, left, mid) + jisuan(nums, mid, right);
        int m = mid, n = mid;
        for (int i = left; i < mid; i++) {
            while(m < right && preSum[m] - preSum[i] < low)
                m++;
            while(n < right && preSum[n] - preSum[i] <= upp)
                n++;
            ans += n - m;
        }
        inplace_merge(preSum + left, preSum + mid, preSum + right);
        return ans;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        low = lower, upp = upper;
        for(int i = 1; i <= n; ++i)preSum[i] = preSum[i - 1] + nums[i - 1];
        
        return jisuan(nums, 0, n + 1);
        
    }
};
