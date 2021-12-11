//
//Runtime 212 
//Memory Usage 245.2 
class StreamChecker {
    int trie[80000][26] = {{0}};
    int tot = 0;
    bool has[80000] = {false};
    void insert(const string &s){
        int cur = 0;
        for(int i = s.size() - 1; i >= 0; --i){
            if(!trie[cur][s[i] - 'a'])trie[cur][s[i] - 'a'] = ++tot;
            cur = trie[cur][s[i] - 'a'];
        }
        has[cur] = true;
    }
    bool search(const string &s){
        int cur = 0;
        for(int i = s.size() - 1; i >= 0; --i){
            if(has[cur])return true;
            if(!trie[cur][s[i] - 'a'])return false;
            cur = trie[cur][s[i] - 'a'];
        }
        return has[cur];
        
    }
    
public:
    StreamChecker(vector<string>& words) {
        for(const string &s : words){
            insert(s);    
        }
    }
    
    bool query(char letter) {
        q += letter;
        return search(q);
    }
    string q;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
