//
//Runtime 161
//Memory Usage 62.6

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        vector<int> q;

        int res = INT_MAX;

        for(const int num : arr) {
            for(auto &a : q)
                a &= num;
            q.push_back(num);
            q.erase(unique(q.begin(), q.end()), q.end());
            for (auto x : q) 
                res = min(res, abs(target-x));
        }

        return res;
    }
};