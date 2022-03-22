//Runtime 0
//Memory Usage 6.7
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int idx = -10000, n = s.size();
        vector<int> res(n, INT_MAX);
        for(int i = 0; i < n; ++i){
            if(c == s[i])
                idx = i;
            res[i] = min(res[i], i - idx);
        }
        idx = 10000;
        for(int i = n - 1; i >= 0; --i){
            if(c == s[i])
                idx = i;
            res[i] = min(res[i], idx - i);
        }
        return res;
    }
};