//
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    string toHex(int num) {
        string res;
        unsigned int n= (unsigned int)num;
        while(n){
            res += hex[n & 0xf];
            n >>= 4;
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};
