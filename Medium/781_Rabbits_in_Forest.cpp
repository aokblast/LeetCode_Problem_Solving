//Greedy
//Runtime 3
//Memory Usage 8.5032932i


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(const int ans : answers)
            mp[ans]++;
        int res = 0;
        for(auto [num, cnt] : mp)
            res += (num + 1) * (cnt / (num + 1) + !!(cnt % (num + 1)));
        return res;
    }
};