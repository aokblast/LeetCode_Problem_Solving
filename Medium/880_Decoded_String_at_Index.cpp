//
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long sz = 0;
        for(const char c : s){
            if(isalpha(c))
                ++sz;
            else
                sz *= (c - '0');
        }
        string res;
        
        for(int i = s.size() - 1; i >= 0; --i){
            k %= sz;
            const char c = s[i];
            if(k == 0 && !isdigit(c))
                return res + c;
            if(isdigit(c)){
                sz /= c - '0';
            }else{
                --sz;
            }
        }
        return res + s[0];
    }
};