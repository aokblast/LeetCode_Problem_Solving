//Greedy
//Runtime 0
//Memory Usage 7.7

class Solution {
    int diff[105] = {0};
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int acc = 0, n = costs.size();
        for(int i = 0; i < n; ++i)
            acc += costs[i][0], diff[i] = costs[i][1] - costs[i][0];
        sort(diff, diff + n);
        for(int i = 0; i < n / 2; ++i)
            acc += diff[i];
        return acc;
            
    }
};