//dp
//Runtime 0
//Memory 6
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        int res = 0;
        
        const string s = to_string(n + 1);
        
        int len = s.size();
        
        unordered_set<int> vis;
        
        
        for(int i = 1; i < len; ++i)
            res += 9 * C(9, i - 1);
        

        
        for(int i = 0; i < len; ++i){
            for(int j = i > 0 ? 0 : 1; j < s[i] - '0'; ++j){
                if(vis.count(j))
                    continue;
                res += C(9 - i, len - i - 1);
            }
            if(vis.count(s[i] - '0'))
                break;
            vis.insert(s[i] - '0');
        }
        return n - res;
        
    }
    
    static int C(int m, int n){
        return n == 0 ? 1 : (m - n + 1) * C(m, n - 1);
    }
};