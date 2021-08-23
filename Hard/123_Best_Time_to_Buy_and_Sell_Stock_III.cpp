//dp
//Runtime 112 
//Memory Usage 75.2
class Solution {
public:
    int local[3], global[3];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        for(int i = 1; i < n; ++i){
            int diff = prices[i] - prices[i - 1];
            for(int j = 2; j >= 1; --j){
                local[j] = max(global[j - 1]  + max(diff, 0), local[j] + diff);
                global[j] = max(local[j], global[j]);
            }
        }
        return global[2];
    }
};
