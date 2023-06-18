//Greedy
//Runtime 274
//Memory Usage 92.6
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& pts, int k) {
        priority_queue<pair<int, int>> pq;
        pq.push({pts[0][1] - pts[0][0], pts[0][0]});

        int res = INT_MIN, n = pts.size();

        for(int i = 1; i < n; ++i) {
            int sum = pts[i][0] + pts[i][1];
            while(!pq.empty() && pts[i][0] - pq.top().second > k)
                pq.pop();
            if(!pq.empty())
                res = max(res, sum + pq.top().first);
            pq.push({pts[i][1] - pts[i][0], pts[i][0]});
        }

        return res;
    }
};

static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);