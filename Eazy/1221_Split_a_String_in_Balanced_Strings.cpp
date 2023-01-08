//
//Runtime 0
//Memory Usage 6.1

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        
        int l = 0, r = 0;
        
        for(const char c : s) {
            if(c == 'L')
                ++l;
            else
                ++r;
            
            if(l == r)
                ++res;
        }
        
        return res;
    }
};