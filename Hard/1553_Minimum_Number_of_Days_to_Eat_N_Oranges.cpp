//DFS
//Runtime 4
//Memory 9.7
class Solution {
    unordered_map<int, int> dp;
public:
    int minDays(int n) {
        return n <= 1 ? 1 : (dp.count(n) ? dp[n] : (dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3))));
    }
};