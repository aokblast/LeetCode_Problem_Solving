//
//Runtime 0
//Memory 6.1
class Solution {
public:
    static double f(string &s){
        int i = s.find('(');
        if(i == -1)
            return stod(s);
        string res = s.substr(0, i);
        string rep = s.substr(i + 1, s.size() - i - 2);

        for(i = 17; i; --i)
            res += rep;
        return stod(res);
        
    }
    bool isRationalEqual(string s, string t) {
        return f(s) == f(t);
    }
};