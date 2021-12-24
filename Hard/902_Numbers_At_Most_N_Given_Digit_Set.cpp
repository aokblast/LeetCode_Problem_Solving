//
//Runtime: 0
//Memory Usage: 8.1

class Solution {
public:
    
    int atMostNGivenDigitSet(vector<string>& digits, int nu) {
        string num = to_string(nu);
        int n = digits.size(), len = num.size(), res = 0;
        for(int i = 1; i < len; ++i) res += pow(n, i);
        for(int i = 0; i < len; ++i){
            bool hasNum = false; 
            for(const auto &dig : digits){
                if(dig[0] < num[i]) res += pow(n, len - i - 1);
                else if(dig[0] == num[i])hasNum = true;
                else break;
            }
            if(!hasNum)return res;
        }
        return res + 1;
        
    }
};