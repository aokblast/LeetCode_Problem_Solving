//
//Runtime 8
//Memory Usage 13.2
class Solution {
public:
    bool cow[205] = {false};
    bool row[205] = {false};
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(matrix[i][j] == 0){
                    cow[i] = true;
                    row[j] = true;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            if(cow[i]){
                for(int  j = 0; j < m; ++j) matrix[i][j] = 0;
            }
        }
        for(int i = 0; i < m; ++i){
            if(row[i]){
                for(int  j = 0; j < n; ++j) matrix[j][i] = 0;
            }
        }

    }
};
