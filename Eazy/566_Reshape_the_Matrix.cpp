//
//Runtime 8
//Memory Usage 10.8

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m * n != r * c)return mat;
        vector<vector<int>> res(r, vector<int>(c));
        int i = 0;
        for(auto &v : res){
            for(auto &num : v){
                num = mat[i / n][i % n];
                ++i;
            }
        }
        return res;
    }
};