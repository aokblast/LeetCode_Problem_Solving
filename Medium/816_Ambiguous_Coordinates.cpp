//
//Runtime 3
//Memory Usage 9

class Solution {
public:
    void gen(string &&s, vector<string> &res){
        res.clear();
        
        if(s[0] == '0' && s.back() == '0' && s.size() > 1)
            return ;
        if(s.back() == '0'){
            res.emplace_back(s);
            return;
        }
        if(s[0] == '0'){
            res.emplace_back("0." + s.substr(1));
            return;
        }
        res.emplace_back(s);
        
        for(int i = 1; i < s.size(); ++i){
            res.emplace_back(s.substr(0, i) + "." + s.substr(i));
        }
        
    }

    vector<string> ambiguousCoordinates(string s) {
        vector<string> res, l, r;
        for(int i = 2; i <= s.size() - 2;++i){
            gen(s.substr(1, i - 1), l);
            gen(s.substr(i, s.size() - 1 - i), r);
            for(const auto &a: l)
                for(const auto &b : r)
                    res.emplace_back("(" + a + ", " + b + ")");
            
        }
        return res;
        
        
    }
};