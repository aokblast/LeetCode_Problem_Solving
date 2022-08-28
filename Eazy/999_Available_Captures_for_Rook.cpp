//Runtime 0
//Memory Usage 6.8
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size(), x, y;
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(board[i][j] == 'R'){
                    x = i, y = j;
                    break;
                }
        int cur = x;
        int res = 0;
        while(cur >= 0){
            res += board[cur][y] == 'p';
            if(board[cur][y] == 'B' || board[cur][y] == 'p')
                break;
            --cur;
        }
        cur = x;
        while(cur < n){
            res += board[cur][y] == 'p';
            if(board[cur][y] == 'B' || board[cur][y] == 'p')
                break;
            ++cur;
        }
        cur = y;
        while(cur < m){
            res += board[x][cur] == 'p';
            if(board[x][cur] == 'B' || board[x][cur] == 'p')
                break;
            
            ++cur;
        }
        cur = y;
        while(cur >= 0){
            res += board[x][cur] == 'p';
            if(board[x][cur] == 'B' || board[x][cur] == 'p')
                break;
            --cur;
        }
        return res;
    }
};