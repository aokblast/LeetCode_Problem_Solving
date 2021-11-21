//
//Runtime 40 
//Memory Usage 11.6
class Solution {
public:
    unordered_map<string, int> m;
    int n;
    int dfs(int idx, int mask){
        if(idx > n)return 1;
        string s = to_string(mask) + to_string(idx);
        if(m.find(s) != m.end()){
            return m[s];
        }
        int &cur = m[s];
        for(int i = 1; i <= n; ++i){
            int ma = 1 << i;
            if(!(mask & (ma)) && (!(idx % i) || !(i % idx))){
                mask ^= ma;
                cur += dfs(idx + 1, mask);
                mask ^= ma;
            }
        }
        return cur;
    }
    int countArrangement(int _n) {
        n = _n;
        return dfs(1, 0);
    }
};
