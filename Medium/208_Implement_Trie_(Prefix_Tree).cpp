//
//Runtime 44
//Memory Usage 94.2
class Trie {
public:
    /** Initialize your data structure here. */
    int trie[40000][26] = {{0}};
    int val[40000] = {0};
    int f = 0;
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int top = 0;
        for(int i = 0; i < word.size(); ++i){
            if(!trie[top][word[i] - 'a']) trie[top][word[i] - 'a'] = ++f;
            top = trie[top][word[i] - 'a'];
        }
        ++val[top];
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int top = 0;
        for(int i = 0; i < word.size(); ++i){
            if(!trie[top][word[i] - 'a']) return false;
            top = trie[top][word[i] - 'a'];
        }
        return val[top];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int top = 0;
        for(int i = 0; i < prefix.size(); ++i){
            if(!trie[top][prefix[i] - 'a']) return false;
            top = trie[top][prefix[i] - 'a'];
        }
        for(int i = 0; i < 26; ++i){
            if(trie[top][i]) return true;
        }
        return val[top];
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
