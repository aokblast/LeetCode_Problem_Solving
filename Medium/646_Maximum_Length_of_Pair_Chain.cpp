//greedy
//Runtime 36
//Memory Usage 24
class Solution {
public:
    int findLongestChain(vector<vector<int>>& _pairs) {
        int n = _pairs.size();
        vector<pair<int, int>> pairs;
        for(const auto &vec : _pairs){
            pairs.emplace_back(make_pair(vec[1], vec[0]));
        }
        sort(pairs.begin(), pairs.end());
        int res = 0,  l = INT_MIN;
        for(const auto &p : pairs){
            if(p.second > l) ++res, l = p.first;
        }
        return res;
    }
};