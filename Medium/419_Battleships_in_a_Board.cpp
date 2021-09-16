//dfs
//Runtime 6
//Memory Usage 8.3
class Solution {
public:
    enum dir{
        VIRT,
        HORI
    };
    bool visit[205][205];
    int n, m;
    void dfs(vector<vector<char>>& board, int x, int y, dir d){
        if(x >= n || y >= m || board[x][y] != 'X')return;
        
        visit[x][y] = true;
        switch(d){
            case VIRT:
                 dfs(board, x + 1, y, d);
                break;
            case HORI:
                 dfs(board, x, y + 1, d);
                break;
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 'X' && !visit[i][j]){
                    ++ans;
                    dfs(board, i, j, i + 1 < n  && board[i + 1][j] == 'X' ? VIRT : HORI);
                }
            }
        }
        return ans;
    }
};
