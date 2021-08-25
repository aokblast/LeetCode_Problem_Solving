//
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    bool isUgly(int n) {
        while(!(n % 2)){
            n /= 2;
        }
        while(!(n % 5)){
            n /= 5;
        }
        while(!(n % 3)){
            n /= 3;
        }
        return (n == 1);
    }
};
