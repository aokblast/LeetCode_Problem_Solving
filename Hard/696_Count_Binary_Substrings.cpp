//
//Runtime 24
//Memory 10.6

class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, z = 0, o = 0;
        for(int i = 0; i < s.size(); ++i){
            if(i == 0)
                s[i] == '0' ? ++z :  ++o;
            else{
                if(s[i] == '0'){
                    z = s[i - 1] == '0' ? z + 1 : 1;
                    if(o >= z) ++res;
                }else{
                    o = s[i -  1] == '1' ? o + 1 : 1;
                    if(z >= o) ++res;
                }
            }
        }
        return res;
        
    }
};