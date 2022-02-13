//Trie
//Runtime 560
//Memory 345.8
const int MAXN = 1.5e5 + 5;
class WordFilter {
public:
    struct {
        int t[MAXN][27] = {{0}};
        int v[MAXN] = {0};
        int cnt = 0;
        void insert(const string &s, int val){
            int cur = 0;
            for(const char c : s){
                if(!t[cur][c - 'a'])
                    t[cur][c - 'a'] = ++cnt;
                cur = t[cur][c - 'a'];
            }
            v[cur] = val;
        }
        int query(const string &s){
            int cur = 0;
            for(const char c : s){
                cur = t[cur][c - 'a'];
                if(!cur)
                    return 0;
            }
            return v[cur];
        }
    }t;
    WordFilter(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i){
            string &cur = words[i];
            int len = cur.size();
            string pre, last;
            vector<string> pv(len), lv(len);
            for(int i = 0; i < len; ++i){
                pre += cur[i];
                last = cur[len - i - 1] + last;
                pv[i] = pre, lv[i] = last;
            }
                
            for(const string &s1 : pv){
                for(const string &s2 : lv)
                     t.insert(s1 + (char)('z' + 1) + s2, i + 1);
            }
        }

    }
    
    int f(string prefix, string suffix) {
        return t.query(prefix + (char)('z' + 1) + suffix) - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */