//Greedy
//Runtime 243
//Memory Usage 87.3

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> ps(n);

        for(int i = 0; i < n; ++i)
            ps[i] = {nums2[i], nums1[i]};
        
        sort(ps.begin(), ps.end(), [](const auto &p1, const auto &p2) {return p1.first < p2.first;});

        long long mn = INT_MIN, sum = 0, res = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = n - 1; i >= 0; --i) {
            mn = ps[i].first;
            sum += ps[i].second;
            pq.push(ps[i].second);

            if(pq.size() == k) {
                res = max(res, mn * sum);
                sum -= pq.top();
                pq.pop();
            }
        }

        return res;
    }
};