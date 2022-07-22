//Greedy
//Runtime 0
//Memory Usage 6.2

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        while((a - b) >= 2 && b > 0){
            res += "aa";
            res += "b";
            a -= 2, b -= 1;
        }
        
        while((b - a) >= 2 && a > 0){
            res += "bb";
            res += "a";
            a -= 1, b -= 2;
        }
        
        while(a > 0 && b > 0){
            res += 'a', res += 'b';
            --a, --b;
        }
        
        res += string(a, 'a');
        res += string(b, 'b');
        
        return res;
    }
};
