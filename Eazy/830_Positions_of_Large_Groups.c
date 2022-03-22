//
//Runtime 0
//Memory Usage 7.4

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int l = 0, r = 0, n = s.size();
        vector<vector<int>> res;
        while(r < n){
            char c = s[l];
            while(r < n && c == s[r])
                ++r;
            if(r - l >= 3)
                res.push_back({l, r - 1});
            l = r;
        }
        return res;
    }
};