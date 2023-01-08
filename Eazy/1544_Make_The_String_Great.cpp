//
//Runtime 2
//Memory Usage 6.2

class Solution {
public:
    string makeGood(string s) {
        string res;
        
        for(const char c : s) {
            if(res.size() && res.back() - 32 == c || res.back() + 32 == c) {
                res.pop_back();
                continue;
            }
            
            res += c;
        }
        
        return res;
    }
};