//
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;

        while(numBottles) {
            if(numBottles >= numExchange)
                res += numBottles / numExchange, numBottles = numBottles % numExchange + numBottles / numExchange;
            else
                numBottles = 0;
        }

        return res;
    }
};