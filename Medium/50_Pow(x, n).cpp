//squaring
//Runtime 0
//Memory 5.0
class Solution {
public:
    int size;
    vector<vector<string>> result;
    bool valid(vector<int> &queenCol, int row, int col){
        for(int i = 0; i < row; ++i){
            if(queenCol[i] == col || abs(row - i) == abs(col - queenCol[i]))return false;
        }
        return true;
    }
    
    void dfs(vector<string> &tmp, int layer, vector<int> &queenLoc){
        if(layer == size) result.push_back(tmp);
        for(int i = 0; i < size; ++i){
            if(valid(queenLoc, layer, i)){
                tmp[layer][i] = 'Q';
                queenLoc.push_back(i);
                dfs(tmp, layer + 1, queenLoc);
                queenLoc.pop_back();
                tmp[layer][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        vector<string> tmp(n, string(n, '.'));
        vector<int> loc;
        dfs(tmp, 0, loc);
        return result;
    }
};
