//
//Runtime 50
//Memory Usage 39.5

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), res = INT_MIN, l = values[0];
        
        for(int i = 1; i < n; ++i){
            int val = values[i];
            int r = val - i;
            res = max(res, r + l);
            l = max(l, val + i);
        }
        return res;
    }
};