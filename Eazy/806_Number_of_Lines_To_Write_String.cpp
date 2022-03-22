//
//Runtime 0
//Memory Usage 7

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int res = 0, cur = 0;
        for(const char c : s){
            int w = widths[c - 'a'];
            if(w + cur > 100)
                res++, cur = w;
            else
                cur += w;
        }
        return {res + 1, cur};
    }
};