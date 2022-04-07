//dfs + memo
//Runtime 236
//Memory Usage 11.1
class Solution {
public:
    static int dfs(string &s1, string &s2, unordered_map<string, int> &mp, int i = 0, int j = 0){
        if(i == s1.size())
            return 0;
        if(mp.find(s1) != mp.end())
            return mp[s1];
        if(s1[i] == s2[j])
            return mp[s1] = dfs(s1, s2, mp, i + 1, j + 1);
        int cur = 0x3f3f3f;
        for(int a = i; a < s1.size(); ++a){
            if(s1[a] == s2[j]){
                swap(s1[a], s1[i]);
                cur = min(dfs(s1, s2, mp, i + 1, j + 1), cur);
                swap(s1[a], s1[i]);
            }
        }
        return cur == 0x3f3f3f ? cur : mp[s1] = cur + 1;
        
    }
    static int kSimilarity(string s1, string s2) {
        ios::sync_with_stdio(0);
        cin.tie(nullptr);
        unordered_map<string, int> mp;
        return dfs(s1, s2, mp);
        
        
        
    }
};