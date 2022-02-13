//dp
//Runtime 209
//Memory Usage 16.1


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[1005][1005] = {0};
        int m = nums1.size(), n = nums2.size();
        int res = 0;
        for(int i = 1;  i <= m; ++i )
            for(int j = 1; j <= n; ++j){
                dp[i][j] = nums1[i - 1] == nums2[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
                res = max(res, dp[i][j]);
            }
        return res;
        
    }
};