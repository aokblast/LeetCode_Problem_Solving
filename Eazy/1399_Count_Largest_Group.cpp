//
//Runtime 0
//Memory Usage 6.1

class Solution {
public:
    int countLargestGroup(int n) {
        int cnts[100] = {0}, mx = 0, res = 0;
        for(int i = 1; i <= n; ++i) {
            int cur = 0, j = i;
            while(j) {
                cur += j % 10;
                j /= 10;
            }

            ++cnts[cur];

            if(cnts[cur] > mx)
                mx = cnts[cur], res = 1;
            else if(cnts[cur] == mx)
                ++res;
        }
        return res;
    }
};