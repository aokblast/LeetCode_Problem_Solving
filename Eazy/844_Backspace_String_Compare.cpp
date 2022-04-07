//Runtime 0
//Memory Usage 6.3
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, s2;
        for(const char c : s){
            if(c == '#'){
                if(s1.size())
                    s1.pop_back();
            }else
                s1 += c;
        }
        for(const char c : t){
            if(c == '#'){
                if(s2.size())
                    s2.pop_back();
            }else
                s2 += c;
        }
        return s1 == s2;
    }
};