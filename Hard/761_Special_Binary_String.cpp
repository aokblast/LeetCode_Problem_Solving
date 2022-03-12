//dfs
//Runtime 0
//Memory Usage 6.5

class Solution {
public:
    string dfs(string &s, int l, int r){
        vector<string> v;
        int cnt = 0;
        int d = l;
        for(int i = l; i <= r; ++i){
            cnt += s[i] == '1' ? 1 : -1;
            if(!cnt){
                v.push_back('1' + dfs(s, l + 1, i - 1) + '0');
                l = i + 1;
            }
        }
        sort(v.rbegin(), v.rend());
        string res;
        for(const auto s : v)
            res += s;
        return res;
        
    }
    string makeLargestSpecial(string s) {
        
        return dfs(s, 0, s.size() - 1);
    }
};