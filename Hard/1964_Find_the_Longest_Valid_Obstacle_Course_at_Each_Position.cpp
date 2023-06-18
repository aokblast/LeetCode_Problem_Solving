//LIS
//Runtime 340
//Memory Usage 118.9

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = obstacles.size();
        vector<int> dp(n + 1, 1e9);
        vector<int> res(n);
        int i = 0;

        for(const auto ob : obstacles) {
            auto iter = upper_bound(dp.begin(), dp.end(), ob);
            *iter = ob;
            res[i++] = (iter - dp.begin() + 1);
        }
        
        return res;
    }
};