//
//Runtime 48
//Memory Usage 21.7
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int n = img.size(), m = img[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int tmp = 0, cnt = 0;
                for(int x = -1; x <= 1; ++x){
                    for(int y = -1; y <= 1; ++y){
                        if(i + x < 0 || y + j < 0 || x + i >= n || y + j >= m)continue;
                        tmp += img[i + x][j + y];
                        ++cnt;
                    }
                }
                res[i][j] = tmp / cnt;
            }
        }
        return res;
    }
};