//
//Runtime 67
//Memory Usage 25.9

class Solution {
public:
    string removeStars(string s) {
        string res;

        for(const char c : s)
            if(c == '*')
                res.pop_back();
            else
                res += c;
        
        return res;
    }
};