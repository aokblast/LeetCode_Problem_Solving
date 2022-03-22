//Greedy
//Runtime 86
//Memory Usage 35.3
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size(), m = worker.size();
        int res = 0;
        pair<int, int> ps[10005];
        for(int i = 0; i < n; ++i)
            ps[i] = {profit[i], difficulty[i]};
        sort(ps, ps + n);
        sort(worker.begin(), worker.end());
        int i = n - 1, j = m - 1;
        while(i >= 0 && j >= 0){
            while(j >= 0 && worker[j] >= ps[i].second)
                --j, res += ps[i].first;
            --i;
        }
        return res;
        
    }
};