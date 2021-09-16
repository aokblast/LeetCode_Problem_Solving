//
//Runtime 0
//Memory Usage 6.3
class Solution {
public:
    string decodeString(string s) {
        string res;
        
        for(int i = 0; i < s.size(); ++i){
            if(isdigit(s[i])){
                
                int num = s[i] - '0';
                while(isdigit(s[++i])) num = num * 10 + (s[i] - '0');
                
                int j = i + 1;
                int layer = 1;
                
                while(layer){layer += (s[j] == '[' ? 1 : (s[j] == ']' ? - 1 : 0)), ++j;}
                
                string tmp = decodeString(s.substr(i + 1, j - i - 2));
                
                while(num--){
                    res += tmp;
                }
                i = j - 1;

            }else{
                res += s[i];
            }
        }
        return res;
    }
};
