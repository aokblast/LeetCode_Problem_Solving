//dfs
//Runtime 0
//Memory Usage 6.4

class Solution {
public:
    vector<int> res;
    void dfs(int l, int h, int i, int val){
        val = val * 10 + i;
        if(val >= l && val <= h)
            res.push_back(val);
        if(val > h || i == 9)
            return;
        dfs(l, h, i + 1, val);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1; i <= 9; ++i)
            dfs(low, high, i, 0);
        sort(res.begin(), res.end());
        return res;
    }
};