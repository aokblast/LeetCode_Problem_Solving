//
//Runtime 0
//Memory Usage 9.4
class Solution {
public:
    int mp[26];
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < 26; ++i)
            mp[order[i] - 'a'] = i;
        
        for(int i = 1; i < words.size(); ++i){
            const auto &s1 = words[i - 1];
            const auto &s2 = words[i];
            
            int l1 = s1.size(), l2 = s2.size(), lim = min(l1, l2);
            bool diff = false;
            for(int j = 0; j < lim; ++j){
                if(s1[j] == s2[j])
                    continue;
                diff = true;
                if(mp[s1[j] - 'a'] > mp[s2[j] - 'a'])
                    return false;
                else
                    break;
            }
            if(!diff && l1 > l2)
                return false;
            
        }
        return true;
        
    }
};