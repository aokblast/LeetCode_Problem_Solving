//
//Runtime 0
//Memory Usage 7.1
class Solution {
public:
    double average(vector<int>& salary) {
        int mx = INT_MIN, mn = INT_MAX, sum = 0;

        for(const auto s : salary)
            mx = max(mx, s), mn = min(mn, s), sum += s;

        return (double)(sum - mx - mn) / (salary.size() - 2);
    }
};