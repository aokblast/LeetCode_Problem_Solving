//
//Runtime 0
//Memory 7
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size - i; ++j){
               swap(matrix[i][j], matrix[size - j - 1][size - i - 1]);
                
            }
        }
        reverse(matrix.begin(), matrix.end());
    }
};
