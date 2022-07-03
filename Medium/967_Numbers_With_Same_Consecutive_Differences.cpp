//dfs
//Runtime 0
//Memory Usage 8.8

class Solution {
public:
    int K, N;
    vector<int> res;
    void dfs(int cur, int last, int digs){
        if(digs == N)
            return void(res.push_back(cur));
        cur *= 10;
        if(last - K >= 0)
            dfs(cur + last - K, last - K, digs + 1);
        
        if(last + K <= 9 && last + K != last - K)
            dfs(cur + last + K, last + K, digs + 1);
            
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        N = n, K = k;
        for(int i = 1; i <= 9; ++i)
            dfs(i, i, 1);
        
        return res;
    }
};