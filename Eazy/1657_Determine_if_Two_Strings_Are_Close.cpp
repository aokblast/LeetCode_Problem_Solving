//
//Runtime 65
//Memory Usage 20.5

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size())
            return false;
        
        int n = word1.size();
        
        int cnt1[26] = {0}, cnt2[26] = {0};
        
        for(int i = 0; i < n; ++i)
            cnt1[word1[i] - 'a']++, cnt2[word2[i] - 'a']++;
        
        for(int i = 0; i < 26; ++i)
            if((!!cnt1[i]) ^ (!!cnt2[i]))
                return false;
        
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        
        for(int i = 0; i < 26; ++i)
            if(cnt1[i] != cnt2[i])
                return false;
        
        return true;

    }
};