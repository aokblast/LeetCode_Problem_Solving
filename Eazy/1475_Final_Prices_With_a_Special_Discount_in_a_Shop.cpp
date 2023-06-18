//Greedy
//Runtime 0
//Memory Usage 9.9

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        vector<int> res;

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(prices[i] >= prices[j]) {
                    prices[i] -= prices[j];
                    break;
                }
            }
            res.push_back(prices[i]);
        }

        return res;
    }
};