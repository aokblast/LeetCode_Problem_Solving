//
//Runtime 0 
//Memory Usage 5.9
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)return 1;
        int cnt = 0;
        int cu = n;
        while(n) n >>= 1, ++cnt;
        return ~cu & ((1 << cnt) - 1);
    }
};