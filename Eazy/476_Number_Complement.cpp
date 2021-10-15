//
//Runtime 0 
//Memory Usage  5.9
class Solution {
public:
    inline int cnt(int num){
        int ans = 0;
        for(;num; ++ans, num >>= 1);
        return ans;
    }
    int findComplement(int num) {
        return (1L << (cnt(num))) - num - 1;
    }
};
