//Trie
//Runtime 0
//Memory Usage 28.9

class MapSum {
public:
    struct trie{
        int val[5000] = {0};
        int tr[5000][26] = {{0}};
        int tot = 0;
        void insert(const string &key, int v){
            int cur = 0;
            for(const char c : key){
                if(!tr[cur][c - 'a'])
                    tr[cur][c - 'a'] = ++tot;
                cur = tr[cur][c - 'a'];
            }
            val[cur] = v;
        }
        int search(const string &key){
            int cur = 0;
            for(const char c : key){
                if(!tr[cur][c - 'a'])
                    return 0;
                cur = tr[cur][c - 'a'];
            }
            return dfs(cur);
        }
        private:
        int dfs(int u){
            if(!u)
                return 0;
            int res = 0;
            for(int i = 0; i < 26; ++i)
                res += dfs(tr[u][i]);
            return res + val[u];
        }
        
    } t;
    
    
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        t.insert(key, val);
    }
    
    int sum(string prefix) {
        return t.search(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
