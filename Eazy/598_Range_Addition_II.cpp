//
//Runtime 8
//Memory Usage 11.1
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int ans = 0, a = m, b = n;
        for(const auto &v : ops){
            a = min(a, v[0]), b = min(b, v[1]);
        }
        return a * b;
    }
};