//
//Runtime 113
//Memory Usgae 55

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sold = 0, hold = -prices[0];
        for(const int price : prices){
            int t = sold;
            sold = max(sold, hold + price - fee);
            hold = max(hold, t - price);
        }
        return sold;
    }
};