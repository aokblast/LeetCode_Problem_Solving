//dfs
//Runtime 8 
//Memory Usage 9.9
class Solution {
public:
    bool hasX[205][205];
    int n, m;
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if( i == 0 || j == 0 || j == m - 1 || i == n - 1) dfs(board, i, j);
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '@') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        if(board[x][y] == 'O'){
            board[x][y] = '@';
            if(x > 0) dfs(board,x- 1, y);
            if(x < n - 1) dfs(board, x + 1, y);
            if(y > 0) dfs(board,x, y - 1);
            if(y < m - 1) dfs(board, x, y + 1);
        }
    }
};
