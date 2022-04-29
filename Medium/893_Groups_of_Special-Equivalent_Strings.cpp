//
//Runtime 8
//Memory Usage 8.8

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_map<string, int> mp;
        for(const string &word : words){
            string s[2];
            for(int i = 0; i < word.size(); ++i)
                s[i % 2]  += word[i];
            
            sort(s[0].begin(), s[0].end());
            sort(s[1].begin(), s[1].end());
            ++mp[s[0] + s[1]];
        }
        
        return mp.size();    
        
    }
};