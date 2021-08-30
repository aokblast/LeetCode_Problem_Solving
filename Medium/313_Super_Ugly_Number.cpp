//dp
//Runtime 728
//Memory Usage 12.4
class Solution {
public:
    int back[100] = {0};
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int s = primes.size();
        int next = 1;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i){
            dp[i] = next;
            next = INT_MAX;
            for(int j = 0; j < s; ++j){
                back[j] += (dp[i] == (primes[j] * dp[back[j]]));
                next = min(primes[j] * dp[back[j]], next);
            }
        }
        return dp[n - 1];
    }
};
