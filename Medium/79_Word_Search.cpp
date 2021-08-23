//DFS
//Runtime 168
//Memory Usage 7.4
class Solution {
public:
    int m, n, size;
    bool visit[6][6];
    int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    
    bool dfs(vector<vector<char>> &board, string &word, int x, int y, int index){
        visit[x][y] = true;
        if(index == size - 1 && board[x][y] == word[index]) return true;
        if(board[x][y] != word[index]) return false;
        int next_x, next_y;
        for(int i = 0; i < 4; ++i){
            next_x = x + dir[i][0];
            next_y = y + dir[i][1];
            if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visit[next_x][next_y]) continue;
            if(dfs(board, word, next_x, next_y, index + 1)) return true;
            visit[next_x][next_y] = false;
        }
        return false;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size(), size = word.length();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                memset(visit, 0, sizeof(visit));
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
        
    }
};
