//DFS
//Runtime 0
//Memory Usage 39.2

class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {

        int x = click[0], y = click[1];
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return board;
        }else{
            dfs(board, x, y);
            return board;
        }
    }
    private int[][] dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    private void dfs(char [][]board, int x, int y){
        if(board[x][y] == 'E'){
            int cnt = 0;
            for(int i = 0; i < 8; ++i){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx >= board.length || nx < 0 || ny < 0 || ny >= board[0].length)continue;
                if(board[nx][ny] == 'M')  ++cnt;
            }
            if(cnt == 0){
                board[x][y] = 'B';
                for(int i = 0; i < 8; ++i){
                    int nx = x + dir[i][0], ny = y + dir[i][1];
                    if(nx >= board.length || nx < 0 || ny < 0 || ny >= board[0].length)continue;
                    dfs(board, nx, ny);
                }
            }else{
                board[x][y] = (char)('0' + cnt);
            }

        }
        return ;
    }
}