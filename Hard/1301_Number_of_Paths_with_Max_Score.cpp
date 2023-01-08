//dp
//Runtime 14
//Memory Usage 9

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();

        constexpr static int dirs[3][2] = {-1, 0, 0, -1, -1, -1};
        constexpr static int MOD = 1e9 + 7;

        vector<vector<int>> scores(vector<vector<int>>(n, vector<int>(m, 0)));
        vector<vector<int>> dp(vector<vector<int>>(n, vector<int>(m, 0)));

        dp[n - 1][m - 1] = 1;
        board[0][0] = '0';

        for(int x = n - 1; x >= 0; --x) {
            for(int y = m - 1; y >= 0; --y) {
                if(dp[x][y] == 0 || board[x][y] == 'X')
                    continue;
                for(int i = 0; i < 3; ++i) {
                    int xx = x + dirs[i][0], yy = y + dirs[i][1];

                    if(xx < 0 || yy < 0 || xx >= n || yy >= m ) 
                        continue;

                    int pp = scores[x][y] + board[xx][yy] - '0';
                    if(pp > scores[xx][yy])
                        scores[xx][yy] = pp, dp[xx][yy] = dp[x][y];
                    else if(pp == scores[xx][yy])
                        dp[xx][yy] = (dp[xx][yy] + dp[x][y]) % MOD;

                }
            }
        }

        return {scores[0][0], dp[0][0]};

    }
};