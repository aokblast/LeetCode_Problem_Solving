//
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1, s = 0;

        while(n) 
            p *= n % 10, s += n % 10, n /= 10;

        return p - s;
    }
};