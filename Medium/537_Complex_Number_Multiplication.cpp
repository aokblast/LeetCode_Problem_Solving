//
//Runtime 0
//Memory Usage 6
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        stringstream s1(num1), s2(num2);
        int r1 = 0, r2 = 0, i1 = 0, i2 = 0;
        char c;
        s1 >> r1 >> c >> i1;
        s2 >> r2 >> c >> i2;
        int n1 = r1 * r2 - i1 * i2;
        int n2 = r1 * i2 + r2 * i1;
        return to_string(n1) + '+' + to_string(n2) + 'i'; 
    }
};
