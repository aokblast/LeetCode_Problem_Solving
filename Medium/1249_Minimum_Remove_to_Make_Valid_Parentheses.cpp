//
//Runtime 24
//Memory Usage 16.1

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        vector<int> ls, rs;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            char c = s[i];
            if(c == '(')
                ls.push_back(i);
            else if(c == ')' && ls.size() >= rs.size() + 1)
                rs.push_back(i);
        }

        while(ls.size() > rs.size())
            ls.pop_back();
        int l = 0, r = 0;
        string res;
        for(int i = 0; i < n; ++i){
            char c = s[i];
            if(c == '('){
                if(l < ls.size() && i == ls[l])
                    res += '(', ++l;
            }else if(c == ')'){
                if(r < rs.size() && i == rs[r])
                    res += ')', ++r;
            }else{
                res += c;
            }
            
        }
        return res;
    }
};