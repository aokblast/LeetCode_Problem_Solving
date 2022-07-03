//Greedy
//Runtime 81
//Memory Usage 32.4

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0), horizontalCuts.push_back(h), verticalCuts.push_back(w), verticalCuts.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end()), sort(verticalCuts.begin(), verticalCuts.end());
        
        int a = 0, b = 0;
        
        for(int i = 1; i < horizontalCuts.size(); ++i)
            a = max(a, horizontalCuts[i] - horizontalCuts[i - 1]);
        
        for(int i = 1; i < verticalCuts.size(); ++i)
            b = max(b, verticalCuts[i] - verticalCuts[i - 1]);
        
        const long MOD = 1e9 + 7;
        return (long)a * b % MOD;
        
        
    }
};