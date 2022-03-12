//
//Runtime 0
//Memory 8.5
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x = 0, o = 0, rx = 0, ro = 0, cx = 0, co = 0, lo = 0, uo = 0, lx = 0, ux = 0, xcnt = 0, ocnt = 0;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                x += board[i][j] == 'X';
                o += board[i][j] == 'O';
                rx += board[i][j] == 'X';
                ro += board[i][j] == 'O';
                cx += board[j][i] == 'X';
                co += board[j][i] == 'O';
            }
            xcnt += (rx == 3) + (cx == 3);
            ocnt += (ro == 3) + (co == 3);
            rx = ro = cx = co = 0;
            lo += board[i][i] == 'O';
            lx += board[i][i] == 'X';
            uo += board[2 - i][i] == 'O';
            ux += board[2 - i][i] == 'X';
        }
        
        ocnt += (uo == 3) + (lo == 3);
        xcnt += (lx == 3) + (ux == 3);
        int cnt = xcnt + ocnt;
        return (x == o || x == o + 1) && (cnt == 0 || ((xcnt == 2 || ocnt == 2) && x == 5 && o == 4) || (cnt == 1 && ((x == o + 1 && xcnt == 1) || (x == o && ocnt == 1))));

    }
};