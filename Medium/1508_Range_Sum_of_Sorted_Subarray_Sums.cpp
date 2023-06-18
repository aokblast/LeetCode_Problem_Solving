//Greedy
//Runtime 129
//Memory Usage 7.9

class Solution {
public:
    using pii = pair<int, int>;
    struct cmp {
        bool operator()(const pii &p1, const pii &p2) {
            return p1.first > p2.first;
        }
    };
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int res = 0;
        priority_queue<pii, vector<pii>, cmp> pq;

        constexpr static int MOD = 1e9 + 7;

        for(int i = 0; i < n; ++i)
            pq.push({nums[i], i});
        

        for(int i = 1; i <= right; ++i) {
            auto [num, idx] = pq.top(); pq.pop();

            if(i >= left) {
                res = res += num;
                if(res >= MOD)
                    res -= MOD;
            }

            if(idx + 1 < n)
                pq.push({num + nums[idx + 1], idx + 1});
        }

        return res;
    }
};