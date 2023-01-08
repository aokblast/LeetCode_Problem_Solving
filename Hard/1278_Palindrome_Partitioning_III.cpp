//dp
//Runtime 7
//Memory Usage 6.3

class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        int dp1[n + 1][n + 1], dp2[k + 1][n + 1];

        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));


        for(int l = 2; l <= n; ++l) {
            
            for(int a = 0; a + l <= n; ++a) {
                int b = a + l - 1;
                dp1[a][b] = dp1[a + 1][b - 1] + (s[a] != s[b]);
            }

            dp2[1][n - l] = dp1[n - l][n - 1];
        }

        for(int K = 2; K <= k; ++K) {
            for(int l = 0; l + K <= n; ++l) {
                dp2[K][l] = INT_MAX;
                for(int r = l; r + K <= n; ++r) 
                    dp2[K][l] = min(dp2[K][l], dp2[K - 1][r + 1] + dp1[l][r]);
            }
        }
        
        return dp2[k][0];
        

    }
};