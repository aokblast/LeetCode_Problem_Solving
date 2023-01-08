//
//Runtime 48
//Memory Usage 18.4
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size(), a = 0, b = 1, len = 0;
        
        while(b + len < n) {
            if(s[a + len] == s[b + len])
                ++len;
            else if(s[a + len] < s[b + len]) 
                a = max(a + len + 1, b), b = a + 1, len = 0;
            else
                b += len + 1, len = 0;
        }
        
        return s.substr(a);
    }
};