//dfs
//Runtime 0
//Memory 6.1
class Solution {
public:
    int size;
    int result;
    bool valid(vector<int> &queenCol, int row, int col){
        for(int i = 0; i < row; ++i){
            if(queenCol[i] == col || abs(row - i) == abs(col - queenCol[i]))return false;
        }
        return true;
    }
    
    void dfs(int layer, vector<int> &queenLoc){
        if(layer == size) ++result;
        for(int i = 0; i < size; ++i){
            if(valid(queenLoc, layer, i)){
                queenLoc.push_back(i);
                dfs(layer + 1, queenLoc);
                queenLoc.pop_back();
            }
        }
    }
    
    int totalNQueens(int n) {
        size = n;
        vector<int> loc;
        dfs(0, loc);
        return result;
    }
};
