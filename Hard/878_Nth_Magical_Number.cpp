//binary Search
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    long M = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        long lcm = ((long)a * b) / gcd(a, b), left = 2, right = 1e16;
        while(left < right){
            long mid = left + ((right - left) >> 1);
            if(mid / a + mid / b - mid / lcm < n)left = mid + 1;
            else right = mid;
            
        }
        return right % M;
    }
    long gcd(long a, long b){
        return b == 0 ? a : gcd(b, a % b);
    }
};