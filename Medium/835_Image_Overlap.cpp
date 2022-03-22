//
//Runtime 19
//Memory 9.7
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res = 0, n = img1.size();
        vector<pair<int, int>> as, bs;
        int cnt[100][100] = {0};
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(img1[i][j])
                    as.push_back({i, j});
                if(img2[i][j])
                    bs.push_back({i, j});
            }
        }
        for(const auto [x1, y1] : as)
            for(const auto [x2, y2] : bs)
                res = max(res, ++cnt[x2 - x1 + 50][y2 - y1 + 50]);
        
        return res;
        
    }
};