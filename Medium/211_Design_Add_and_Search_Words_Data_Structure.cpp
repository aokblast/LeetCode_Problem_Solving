//trie
//Runtime 52
//Memory Usage 103.4 
class WordDictionary {
public:
    /** Initialize your data structure here. */
    int trie[50000][26] = {{0}};
    int ind = 0;
    int val[50000];
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        int size = word.size();
        int top = 0;
        for(int i = 0; i < size; ++i){
            if(!trie[top][word[i] - 'a'])trie[top][word[i] - 'a'] = ++ind;
            top = trie[top][word[i] - 'a'];
        }
        ++val[top];
    }
        bool dfs(const char *word, int top){
        if(*word == '\0') return val[top];
        if(*word == '.' ){
            for(int i = 0; i < 26; ++i){
                if(trie[top][i] && dfs(word + 1, trie[top][i])) return true;
            }
            return false;
        }else{
            if(!trie[top][*word - 'a']) return false;
            else return dfs(word + 1, trie[top][*word - 'a']);
        }
    }
    bool search(string word) {
        return dfs(word.c_str(), 0);
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
