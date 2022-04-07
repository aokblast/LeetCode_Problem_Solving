//Greedy
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        while(target > startValue){
            if(target % 2 == 0)
                target >>= 1;
            else
                ++target;
            ++res;
        }
        return res + startValue - target;
    }
};