//
//Runtime 0
//Memory Usage 6.7

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int mp[26] = {0};
        
        for(const char c : text)
            ++mp[c - 'a'];
        
        return min({mp['b' - 'a'], mp['a' - 'a'], mp['l' - 'a'] / 2, mp['o' - 'a'] / 2, mp['n' - 'a']});
    }
};