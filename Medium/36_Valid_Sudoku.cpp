//
//Runtime 16
//Memory 17.9
class Solution {
public:
    bool colCnt[9][9];
    bool rowCnt[9][9];
    bool tableCnt[9][9];
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                char c = board[i][j];
                if(c != '.'){
                    c = c - '1';
                    if(colCnt[i][c] == true) return false;
                    if(rowCnt[j][c] == true) return false;
                    if(tableCnt[(i / 3) * 3 + (j / 3)][c] == true) return false;
                    
                    colCnt[i][c] = true;
                    rowCnt[j][c] = true;
                    tableCnt[(i / 3) * 3 + (j / 3)][c] = true;

                }
            }
        }
        return true;
    }
};
