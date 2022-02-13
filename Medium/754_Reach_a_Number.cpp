//
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);
        long sum = n * (n + 1) / 2;
        if(sum == target)
            return n;
        if(!((sum - target) % 2))
            return n;
        return n + (n % 2 ? 2 : 1);
    }
};