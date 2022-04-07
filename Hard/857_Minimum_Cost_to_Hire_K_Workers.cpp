//Greedy
//Runtime 43
//Memory Usage  22.6
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double res = DBL_MAX;
        priority_queue<int> pq;
        vector<pair<double, int>> ps;
        int n = quality.size();
        for(int i = 0; i < n; ++i)
            ps.push_back({((double)wage[i]) / quality[i], quality[i]});
        sort(ps.begin(), ps.end());
        
        int sum = 0;
        
        for(const auto [ratio, wk] : ps){
            sum += wk;
            if(pq.size() == k)
                sum -= pq.top(), pq.pop();
            pq.push(wk);
            if(pq.size() == k)
                res = min(res, ratio * sum);
                
        }
        return res;
        
    }
};