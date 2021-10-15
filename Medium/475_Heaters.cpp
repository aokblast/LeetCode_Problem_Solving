//
//Runtime 48
//Memory Usage  25.4
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0, n = heaters.size(), j = 0;
        for(const int &house : houses){
            while(j < n - 1 && abs(house - heaters[j + 1]) <= abs(house - heaters[j]))++j;
            ans = max(ans, abs(house - heaters[j]));
        }
        return ans;
    }
};
