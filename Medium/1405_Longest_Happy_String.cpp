//
//Runtime 0
//Memory Usage 6

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;

        int sz = a + b + c;

        int A = 0, B = 0, C = 0;

        for(int i = 0; i < sz; ++i) {
            if((a >= b && a >= c && A != 2) || (a > 0 && B == 2) || (a > 0 && C == 2) )
                B = 0, C = 0, --a, ++A, res += 'a';
            else if((b >= a && b >= c && B != 2) || (b > 0 && A == 2) || (b > 0 && C == 2))
                A = 0, C = 0, --b, ++B, res += 'b';
            else if((c >= a && c >= b && C != 2) || (c > 0 && A == 2) || (c > 0 && B == 2))
                A = 0, B = 0, --c, ++C, res += 'c';
        }

        return res;
    }
};