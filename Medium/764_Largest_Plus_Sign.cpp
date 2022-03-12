//d[]
//Runtime 116
//Memory Usage 19.6

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int dp[500][500] = {{0}}, arr[500][500] = {0};
        memset(arr, 1, sizeof(arr));
        for(const auto &mine : mines)
            arr[mine[0]][mine[1]] = false;
        int cnt = 0, res = 0;
        for(int j = 0; j < n; ++j){
            cnt = 0;
            for(int i = 0; i < n; ++i)
                (cnt = (arr[i][j] ? cnt + 1 : 0)), dp[i][j] = cnt;
            cnt = 0;
            for(int i = n - 1; i >= 0; --i)
                (cnt = (arr[i][j] ? cnt + 1 : 0)), dp[i][j] = min(dp[i][j], cnt);
        }
        for(int j = 0; j < n; ++j){
            cnt = 0;
            for(int i = 0; i < n; ++i)
                (cnt = (arr[j][i] ? cnt + 1 : 0)), dp[j][i] = min(dp[j][i], cnt);
            cnt = 0;
            for(int i = n - 1; i >= 0; --i)
                (cnt = (arr[j][i] ? cnt + 1 : 0)), dp[j][i] = min(dp[j][i], cnt), res = max(res, dp[j][i]);
        }
        return res;
    }
};