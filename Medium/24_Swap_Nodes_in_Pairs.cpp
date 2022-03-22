//
//Runtime 120
//Memory Usage 111.6

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int up[7] = {0}, down[7] = {0}, same[7] = {0}, n = tops.size();
        for(int i = 0; i < n; ++i)
            ++up[tops[i]], ++down[bottoms[i]], same[tops[i]] += tops[i] == bottoms[i];
        int res = INT_MAX;
        for(int i = 1; i <= 6; ++i)
            if(up[i] + down[i] - same[i] == n)
                res = min(res, min(n - up[i], n - down[i]));
        return res == INT_MAX ? -1 : res;
    }
};

