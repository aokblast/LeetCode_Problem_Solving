//
//Runtime 4
//Memory Usage 6.8
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int cur = 1, idx = 1, n = s.size();
        
        do{
            if(s[idx] == '('){
                ++cur;
            }else{
                --cur;
            }
            if(cur == 0){
                idx += 2;
                cur = 1;
            }else{
                res.push_back(s[idx]);
                ++idx;
            }
            
        }while(idx < n);
        return res;
    }
};