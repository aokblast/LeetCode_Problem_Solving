//dp
//Runtime 0
//Memory Usage 5.9

class Solution {
public:
    int numOfWays(int n) {
        long s[] = {6, 6};
        long ns[] = {6, 6};

        constexpr long MOD = 1e9 + 7;

        n--;

        while(n--) {
            s[1] = (3 * s[0] + 2 * ns[0]) % MOD;
            ns[1] = (2 * s[0] + 2 * ns[0]) % MOD;

            s[0] = s[1], ns[0] = ns[1];
        }

        return (ns[1] + s[1]) % MOD;

    }
};