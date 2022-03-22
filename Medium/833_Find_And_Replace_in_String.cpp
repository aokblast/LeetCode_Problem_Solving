//
//Runtime 11
//Memory Usage 10.4
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets){
        int n = indices.size();
        pair<int, int> ps[105];
        for(int i = 0; i < n; ++i)
            ps[i] = {indices[i], i};
        sort(ps, ps + n);
        int l = 0;
        string res;
        for(int i = 0; i < n; ++i){
            auto [a, idx] = ps[i];
            res += s.substr(l, a - l);
            l = a;
            bool ans = true;
            for(int i = a; i < a + sources[idx].size(); ++i){
                if(sources[idx][i - a] != s[i]){
                    ans = false;
                    break;
                }
            }
            if(ans){
                res += targets[idx];
                l += sources[idx].size();
            }

            
        }
        res += s.substr(l, s.size() - l);
        return res;   
    }
};