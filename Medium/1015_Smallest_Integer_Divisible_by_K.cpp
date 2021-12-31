//
//Runtime 0
//Memory Usage  6.1

class Solution {
public:
    bool app[100000] = {false};
    int smallestRepunitDivByK(int k) {
        int res = 1, num = 1;
        while(true){
            if(num % k == 0)return res;
            if(app[num])return -1;
            app[num] = true;
            num = (num * 10 + 1) % k;
            ++res;
        }
        return -1;
    }
};