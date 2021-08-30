//dp
//Runtime 0
//Memory Usgae 11.2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rest=  0, hold = INT_MIN, sold = 0;
        for(int &price : prices){
            int prev = sold;
            sold = hold + price;
            hold = max(hold, rest - price);
            rest = max(rest, prev);
        }
        return max(rest, sold);
    }
};
