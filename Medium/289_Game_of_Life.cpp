//
//Runtime 0
//Memory Usage 7

class Solution {
public:
    int cnt[26][26];
    int m, n;
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j]){
                    if(j)++cnt[i][j - 1];
                    if(j < n - 1)++cnt[i][j + 1];
                    if(i && j)++cnt[i - 1][j - 1];
                    if(i)++cnt[i - 1][j];
                    if(i && j < n -1 )++cnt[i - 1][j + 1];
                    if(i < m - 1 && j)++cnt[i + 1][j - 1];
                    if(i < m - 1)++cnt[i + 1][j];
                    if(i < m - 1 && j < n - 1)++cnt[i + 1][j + 1];
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j  = 0; j < n; ++j){
                if(!board[i][j]) board[i][j] = cnt[i][j] == 3;
                else{
                    board[i][j] = (cnt[i][j] >= 2 && cnt[i][j] <= 3);
                }
            }
        }
    }
};
