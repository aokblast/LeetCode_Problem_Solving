//
//Runtime 43
//Memory Usage 15

class Solution {
public:
    struct{
        int child[10000][26] = {{0}};
        int tot = 0;
        int appear[10000] = {{0}};
        void insert(const string &s){
            int top = 0;
            
            for(int i = s.size() - 1; i >= 0; --i){
                char c = s[i];
                if(!child[top][c - 'a'])
                    child[top][c - 'a'] = ++tot;
                top = child[top][c - 'a'];
            }
            appear[top] = s.size();
        }
        
        int dfs(int u){
            int res = 0;
            for(int i = 0; i < 26; ++i)
                if(child[u][i])
                    res += dfs(child[u][i]);
            return res == 0 ? appear[u] + 1 : res;
        }
    }trie;
    int minimumLengthEncoding(vector<string>& words) {
        for(const string &s : words)
            trie.insert(s);
        return trie.dfs(0);
    }
};