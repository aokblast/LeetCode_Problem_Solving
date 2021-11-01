//
//Runtime 0 
//Memory Usage 5.9
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)return "0";
        string s;
        bool neg = num < 0  ? (num = -num, true) : false;
        while(num){
            s +='0' + num % 7;
            num /= 7;
        }
        s += (neg ? "-" : "");
        reverse(s.begin(), s.end());
        return s;
    }
};
