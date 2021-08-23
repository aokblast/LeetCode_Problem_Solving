//dp
//Runtime 4
//Memory Usage 10.8
class Solution {
public:
    int local[105], global[105];
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        for(int i = 1; i < n; ++i){
            int diff = prices[i] - prices[i - 1];
            for(int j = k; j >= 1; --j){
                local[j] = max(global[j - 1]  + max(diff, 0), local[j] + diff);
                global[j] = max(local[j], global[j]);
            }
        }
        return global[k];
    }
};
