//
//Runtime 0
//Memory Usage 6.1

class Solution {
public:
    int countOdds(int low, int high) {
        low += low % 2 == 0 ? 1 : 0;
        high -= high % 2 == 0 ? 1 : 0;

        return (high - low) / 2 + 1;
    }
};