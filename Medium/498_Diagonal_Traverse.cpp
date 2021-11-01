//
//Runtime 0 
//Memory Usage 6.8
class Solution {
public:
    int m[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for(const string &s : words){
            
            for(int i = 1; i < s.size(); ++i){
                if(m[tolower(s[i]) - 'a'] != m[tolower(s[i - 1]) - 'a'])goto end;
            }
            ans.push_back(s);
            
            end:
            1;
        }
        return ans;
    }
};
