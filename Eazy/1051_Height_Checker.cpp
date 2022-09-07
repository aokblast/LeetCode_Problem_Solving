//Runtime 0
//Memory Usage 8.1
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto ex = heights;
        sort(ex.begin(), ex.end());
        int n = heights.size();
        int res = 0;
        for(int i = 0; i < n; ++i)
            res += ex[i] != heights[i];
        
        return res;
    }
};