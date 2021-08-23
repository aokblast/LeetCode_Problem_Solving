//hash_map
//Runtime 52
//Memory Usage 23.4
static int x = [](){cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); return 0;}();
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> cnt;
        int n = s.size();
        for(int i = 0; i <= n - 10; ++i){
            cnt[s.substr(i, 10)]++;            
        }
        vector<string> ans;
        for(auto &e : cnt){
            if(e.second > 1) ans.push_back(e.first);
        }
        return ans;
    }
};
