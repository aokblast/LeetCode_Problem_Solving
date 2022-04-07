//
//Runtime 4
//Memory Usage 8.5
class Solution {
public:

    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> xs;
        vector<pair<int, int>> ys;
        int n = rectangles.size();
        const int MOD = 1e9 + 7;
        for(int i = 0; i < n; ++i){
            const auto &rec = rectangles[i];
            xs.push_back(rec[0]), xs.push_back(rec[2]);
            ys.push_back({rec[1], i});
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        int xSz = xs.size(), ySz = ys.size();
        long res = 0;
        for(int i = 1; i < xSz; ++i){
            if(xs[i] == xs[i - 1])
                continue;
            long d = xs[i] - xs[i - 1];
            int cur = 0;
            for(const auto [di, idx] : ys){
                const auto &rec = rectangles[idx];
                if(rec[0] <= xs[i - 1] && rec[2] >= xs[i] && rec[3] > cur)
                    res += (d * (rec[3] - max(cur, rec[1]))) % MOD, cur = rec[3];
                
                    
            } 
        }
        
        return res % MOD;
        
    }
};