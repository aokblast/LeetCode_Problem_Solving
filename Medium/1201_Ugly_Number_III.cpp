//
//Runtime 0
//Memory Usage 5.8

typedef unsigned long long ull;
class Solution {
public:
    ull nthUglyNumber(ull n, ull a, ull b, ull c) {
         ull minN = 1, maxN = INT_MAX;
         ull ab = lcm(a, b), bc = lcm(b, c), ac = lcm(a, c), abc = lcm(ab, c);
        while(minN < maxN){
             ull mid = (minN + maxN) / 2;
             ull N = mid / a  + mid / b + mid / c - mid / ab - mid /bc - mid / ac + mid / abc;
            if(N < n) minN = mid + 1;
            else maxN = mid;
        }
        return minN;
    }
};
