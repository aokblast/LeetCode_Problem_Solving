//Trie
//Runtime 36
//Memory Usage 27.4


class Solution {
private:
    struct Trie{
        int tree[50000][26] = {0};
        bool val[50000] = {0};
        int top = 0;
        void insert(const string &s){
            int u = 0;
            for(const char c : s){
                if(!tree[u][c - 'a']) tree[u][c - 'a'] = ++top;
                u = tree[u][c - 'a'];
            }
            val[u] = true;
        }
        string find(const string &s){
            int u = 0;
            string prefix;
            for(const char c : s){
                if(!tree[u][c - 'a']) return s;
                prefix.push_back(c);
                u = tree[u][c - 'a'];
                if(val[u])return prefix;
            }
            return s;
        }
    };
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        stringstream output;
        string s;
        Trie roots;
        for(const auto &dic : dictionary) 
            roots.insert(dic);
        while(ss >> s)
            output << roots.find(s) << ' ';
        
        string res = output.str();
        res.pop_back();
        return res;
    }
};