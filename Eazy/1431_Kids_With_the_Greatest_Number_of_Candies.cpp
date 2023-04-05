//
//Runtime 0
//Memory Usage 8.9

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;

        vector<bool> res;

        for(const auto c : candies)
            mx = max(mx, c);

        for(const auto c : candies)
            res.emplace_back((c + extraCandies) >= mx);

        return res;
    }
};