//
//Runtime 0
//Memory 6.4
class Solution {
public:
    bool queryString(string s, int n) {
        int m = s.size();
        
        unordered_set<int> st;
        
        for(int i = 0; i < m; ++i){
            int cur = 0;
            int lim = max(i - 31, 0);
            s[i] -= '0';
            for(int j = i; j >= lim; --j){
                cur = ((s[j]) << (i - j)) | cur ;
                if(cur > 0 && cur <= n)
                    st.insert(cur);
                if(cur > n)
                    break;
            }
        }
        return st.size() == n;
    }
};