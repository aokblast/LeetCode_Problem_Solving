//dp
//Runtime 169
//Memory Usage 26.1

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr, vector<int>& arr2) {
        int n = arr.size();
    
        set<int> st(arr2.begin(), arr2.end());
        
        int dp[n + 1][n + 1];
        
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = INT_MIN;
        
        for(int j = 1; j <= n; ++j) {
            
            if(arr[j - 1] > dp[0][j - 1])
                dp[0][j] = arr[j - 1];
            
            for(int i = 1; i <= j; ++i) {
                if(arr[j - 1] > dp[i][j - 1])
                    dp[i][j] = arr[j - 1];
                if(auto it = st.upper_bound(dp[i - 1][j - 1]); it != st.end())
                    dp[i][j] = min(dp[i][j], *it);
            }
        }
        
        for(int i = 0; i <= n; ++i)
            if(dp[i][n] != 0x3f3f3f3f)
                return i;
        
        return -1;
    }
};