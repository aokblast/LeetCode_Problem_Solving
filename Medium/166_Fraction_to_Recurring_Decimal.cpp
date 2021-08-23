//
//Runtime 0
//Memory Usage 6.3
class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        string ans;
        int sign = (numerator < 0 ? -1 : 1 ) * (denominator < 0 ? -1 : 1 );
        if(sign == -1 && numerator != 0) ans += '-';
        numerator = abs(numerator);
        denominator = abs(denominator);
        ans += to_string(numerator / denominator);
        numerator %= denominator;
        string inf;
        unordered_map<long long, int> m;
        if(numerator){
            ans += '.';
            int i = 0;
            while(numerator){
                if(m.find(numerator) != m.end()){
                    inf.insert(m[numerator], "(");
                    inf.push_back(')');
                    goto res;
                    break;
                }
                m[numerator] = i++;
                numerator *= 10;
                inf.push_back((numerator / denominator) + '0');
                
                numerator %= denominator;
                
            }
            res:
            ans +=inf ;
        }
        return ans;
        
        
    }
};
