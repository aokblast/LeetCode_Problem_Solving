//dfs
//Runtime 0
//Memory Usage 6
class Solution {
public:
    int integerReplacement(long long n) {
        if(n == 1){
            return 0;
        }
        if(n & 1){
            return min(integerReplacement((n + 1) >> 1), integerReplacement((n - 1) >> 1)) + 2;
        }else{
            return 1 + integerReplacement(n >> 1);
        }
    }
};
