//
//Runtime 200
//Memory Usage 39.9

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> st;
        int r = 0, n = s.size(), cur = 0;
        if(k > n)
            return false;
        while(r < k)
            cur = cur << 1 | (s[r++] - '0');
        int lim = (1 << k) - 1;
        st.insert(cur);
        while(r < n){
            cur = (cur << 1 | (s[r++] - '0')) & lim;
            st.insert(cur);
        }
        return st.size() == (1 << k);
    }
};