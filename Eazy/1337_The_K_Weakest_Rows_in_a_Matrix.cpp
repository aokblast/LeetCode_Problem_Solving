//sort
//Runtime 8
//Memory Usage 10.6
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int, int>> ps(n);
        
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(const int v : mat[i])
                cnt += v;
            ps[i] = {cnt, i};
        }
        sort(ps.begin(), ps.end());
        vector<int> res;
        for(int i = 0; i < k; ++i)
            res.push_back(ps[i].second);
        return res;
    }
};