//
//Runtime 0
//Memory Usage 6.3
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0, n = s.size();
        for(char &c : t){
            if(s[idx] == c) ++idx;
            if(idx == n) return true;
        }
        return idx == n;
    }
};
