//
//Runtime 336
//Memory Usage  44.9
class Solution {
    struct {
        int tr[100005][26] = {0};
        int tot = 0;
        bool has[100005] = {false};
        void insert(const string &s){
            int top  = 0;
            if(s.empty())return;
            for(const char &c : s){
                if(!tr[top][c - 'a']) tr[top][c - 'a'] = ++tot;
                top = tr[top][c - 'a'];
            }
            has[top] = true;
            
        }
        
        bool query(const string &s){
            int n = s.size();
            vector<bool> dp(n + 1);
            if(s.empty())return false;
            dp[0] = true;
        
            for(int i = 0; i < n; ++i){
                if(!dp[i])continue;
                int top = 0;
                for(int j = i; j < n; ++j){
                    dp[j + 1] = dp[j + 1] | has[tr[top][s[j] - 'a']];
                    top = tr[top][s[j] - 'a'];
                    if(!top)break;
                }
            }
            return dp[n];
        }
        
    }trie;
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        ios::sync_with_stdio(false); 
        cin.tie(0);
        sort(words.begin(), words.end(), [](const string &s1, const string &s2)->bool{return s1.size() < s2.size();});
        vector<string> ans;
        for(const string &s : words){
            if(trie.query(s))ans.push_back(s);
            
            trie.insert(s);
        }
        return ans;
    }
};