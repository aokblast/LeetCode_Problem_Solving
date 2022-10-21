//Prefix Sum
//Runtime 235
//Memory Usage 67.7

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n + 1);
        
        for(const auto &book : bookings)
            res[book[1]] -= book[2], res[book[0] - 1] += book[2];
        
        for(int i = 1; i < n; ++i)
            res[i] += res[i - 1];
        res.pop_back();
        
        return res;
    }
};