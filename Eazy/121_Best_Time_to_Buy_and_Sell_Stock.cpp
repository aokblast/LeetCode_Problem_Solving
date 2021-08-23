//
//Runtime 104
//Memory Usage 93.4
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int buy = INT_MAX- 1e5;
        int result = 0;
        for(int i = 0; i < size; ++i){
            if(prices[i] < buy) buy = prices[i];
            else result = max(result, prices[i] - buy);
        }
        return result;
    }
};
