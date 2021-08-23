//
//Runtime 0
//Memory Usage 6.4
class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.size() - 1, lenb = b.size() - 1;
        string result;
        int jin = 0;
        while(lena >= 0 && lenb >= 0){
            int num1 = a[lena--] - '0', num2 = b[lenb--] - '0';
            result += '0' + (num1 ^ num2 ^ jin);
            jin = (num1 & num2 ) | ((num1 | num2) & jin);
        }
        while(lena >= 0){
            int num1 = a[lena--] - '0';
            result += '0' + (num1 ^ jin);
            jin =((num1) & jin);
        }
        while(lenb >= 0){
            int num1 = b[lenb--] - '0';
            result += '0' + (num1 ^ jin);
            jin =((num1) & jin);
        }
        if(jin  == 1){
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
