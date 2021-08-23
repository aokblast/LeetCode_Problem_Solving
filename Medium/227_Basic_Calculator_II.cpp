//
//Runtime 4
//Memory Usage 7.9
class Solution {
public:
    int calculate(string s) {
        int res = 0, tmp = 0, num = 0, n = s.size();
        char op = '+';
        for(int i = 0; i < n; ++i){
            char c = s[i];
            if(isdigit(c)){
                num = num * 10 - '0' + c;
            }
            if(c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1){
                switch(op){
                    case '+': tmp += num; break;
                    case '-': tmp -= num; break;
                    case '*': tmp *= num; break;
                    case '/': tmp /= num; break;
                }
                if(c == '+' || c == '-' || i == n - 1){
                    res += tmp;
                    tmp = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};
