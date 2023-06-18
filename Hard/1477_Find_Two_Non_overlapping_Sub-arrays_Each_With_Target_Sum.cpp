//dp
//Runtime 119
//Memory Usage 81.2
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int dp[n];
        int l = 0, r = 0, sum = 0, lx = INT_MAX, res = INT_MAX;

        while(r < n) {
            sum += arr[r++];
            while(sum > target)
                sum -= arr[l], ++l;
            
            if(sum == target) {
                if(l >= 1 && dp[l - 1] != INT_MAX)
                    res = min(res, dp[l - 1] + r - l);

                lx = min(lx, r - l);
            }
            dp[r - 1] = lx;
        }

        return res == INT_MAX ? -1 : res;
    }
};