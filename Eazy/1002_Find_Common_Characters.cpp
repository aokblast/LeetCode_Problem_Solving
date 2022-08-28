//
//Runtime 7
//Memory Usage 9.1
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int cur[26] = {0};
        int tot[26] = {0};
        memset(tot, 0x3f, sizeof(tot));
        
        for(const auto &word : words){
            for(const char c : word)
                ++cur[c - 'a'];
            
            for(int i = 0; i < 26; ++i)
                tot[i] = min(tot[i], cur[i]), cur[i] = 0;
        }
        
        vector<string> res;
        
        for(int i = 0; i < 26; ++i)
            if(tot[i] != 0x3f3f3f3f)
                while(tot[i]--)
                    res.push_back(string() + (char)(i + 'a'));
                                  
        return res;
    }
};