//
//Runtime 4
//Memory Usage 6.7

class Solution {
public:
    bool halvesAreAlike(string s) {
        int res = 0, n = s.size(), a = 0, b = 0;
        
        const auto isvowel = [](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        for(int i = 0; i < n / 2; ++i) 
            a += isvowerl(s[i]), b += isvowel(s[i + n / 2]);
            
        
        return a == b;
    }
};