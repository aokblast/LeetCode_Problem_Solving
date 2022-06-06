//
//Runtime 0
//Memory Usage 5.9


class Solution {
public:
    int numberOfSteps(int num) {
        int a = 0, b = 0;
        while(num){
            ++a;
            b += num & 1;
            num >>= 1;
        }
        return max(a - 1, 0) + b;
    }
};