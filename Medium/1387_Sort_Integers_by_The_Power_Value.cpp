//
//Runtime 35
//Memory Usage 6.1

class Solution {
    int dfs(int u) {
        return u == 1 ? 1 : (u % 2 == 0 ? dfs(u / 2) : dfs(u * 3 + 1)) + 1;
    };

public:
    int getKth(int lo, int hi, int k) {
        int res[hi - lo + 1];
        int comp[hi + 1];

        for(int cur = lo, i = 0; cur <= hi; ++cur) 
            res[i++] = cur, comp[cur] = dfs(cur);
        

        nth_element(res, res + k - 1, res + (hi - lo + 1), [&](int a, int b) {
            return comp[a] == comp[b] ? a < b : comp[a] < comp[b];
        });

        return res[k - 1];
    }
};