//dp
//Runtime 44
//Memory Usage 24.5
int _unsync_stdio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 42;
}();
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> locs[26];
        for(int i = 0; i < 26; ++i)
            locs[i].push_back(-1);
        for(int i = 0; i < n; ++i)
            locs[s[i] - 'A'].push_back(i);
        int res = 0;
        for(auto &loc : locs){
            loc.push_back(n);
            int sz = loc.size() - 1;
            for(int i = 1; i < sz; ++i)
                res += (loc[i] - loc[i - 1]) * (loc[i + 1] - loc[i]);
        }
        return res;
    }
};