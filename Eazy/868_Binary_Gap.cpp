//
//Runtime 0
//Memory Usage 6

class Solution {
public:
    int binaryGap(int n) {
        int pre = INT_MAX, res = 0, cnt = 0;
        vector<int> arr;
        
        while(n){
            if(n & 1)
                res = max(res, cnt - pre), pre = cnt;
            ++cnt;
            n >>= 1;
        }
        return res;
        
    }
};