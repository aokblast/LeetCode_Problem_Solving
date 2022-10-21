//
//Runtime 0
//Memory Usage 6.4
class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> res(n);
        int cur = 1, i = 0;
        while(candies) {
            if(i == n)
                i = 0;
            int tmp = min(candies, cur);
            res[i++] += tmp;
            candies -= tmp;
            ++cur;
        }
        
        return res;
    }
};