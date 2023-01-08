//trie
//Runtime 148
//Memory Usage 55.6

const int MAXN = 4e4 + 5;

class Solution {
private:
    class Trie {
        int top = 0;
        int child[MAXN][27] = {{0}};
        bool has[MAXN] = {false};
    public:
        bool insert(const string &str) {
            int u = 0;
            
            for(const char c : str) {
                int nx = c == '/' ? 26 : c - 'a';
                
                if(!child[u][nx]) 
                    child[u][nx] = ++top;
                
                u = child[u][nx];
                
                if(has[u] && c == '/')
                    return false;
            
            }
            
            return has[u] = true;
        }
    };
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        sort(folders.begin(), folders.end(), [](const auto &s1, const auto &s2) {return s1.size() < s2.size();});
        
        vector<string> res;
        Trie t;
        
        for(auto &folder : folders) {
            folder += '/';
            bool cur = t.insert(folder);
            folder.pop_back();
            if(cur)
                res.push_back(folder);
        }
        
        return res;
    }
};