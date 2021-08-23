//dp
//Runtime 100
//Memory Usage 75.7

class Solution {
    string tmp;
    vector<vector<string>> result;
public:
    bool isPar(string &s, int left, int right){
        int len = (right - left)/ 2, totalIndex = (right - left) - 1;
        
        for(int i = 0; i < len; ++i){
            if(s[i + left] != s[totalIndex + left - i])return false;
        }
        return true;
    }
    
    
    void dfs(string &s, int index, int len, vector<string> &vec){
        if(index == len) {result.push_back(vec); return; }
        for(int i = index; i < len; ++i) {
            if(isPar(s, index, i  + 1)){
                vec.push_back(string(s.begin() + index, s.begin() + i + 1));
                dfs(s, i  + 1, len, vec);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        int len = s.length();
        vector<string> tmp;
        dfs(s, 0, s.length(), tmp);
        return result;
        
    }
};
