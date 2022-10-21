//Greedy
//Runtime 94
//Memory 36.8
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> vs;
        
        for(int i = 0; i < n; ++i)
            vs.push_back({efficiency[i], speed[i]});
        
        long res = 0, sum = 0;
        
        sort(vs.begin(), vs.end(), greater());
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        int cnt = 0;
        
        for(const auto [eff, sp] : vs) {
            ++cnt;
            sum += sp;
            res = max(res, sum * eff);
            q.push(sp);
            if(cnt >= k)
                sum -= q.top(), q.pop();
        }
        
        return res % (int)(1e9 + 7);
    }
};