//dp
//Runtime 136
//Memory 49.4

class Solution {
    struct E {
        int s, t, p;
        bool operator<(const E& rhs) const {
            return t == rhs.t ? p > rhs.p : t < rhs.t;
        }
    };
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        vector<E> vs;
        
        for(int i = 0; i < n; ++i) 
            vs.push_back({startTime[i], endTime[i], profit[i]});
        
        sort(vs.begin(), vs.end());
        
        int dp[n + 1], res = 0;
        memset(dp, 0, sizeof(dp));
        dp[0] = vs[0].p;
        
        
        for(int i = 1; i < n; ++i) {
                        
            const auto bs = [&](int l, int r) {
                int res = -1;
                
                while(l <= r) {
                    int mid = l + (r - l) / 2;
                    if(vs[mid].t <= vs[i].s) {
                        res = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                
                return res;
            };
            
        
            int idx = bs(0, i - 1);
            
            int dothis = vs[i].p;
            
            if(idx != -1) {
                dothis += dp[idx];
            }
            
            
            dp[i] = max(dothis, dp[i - 1]);
        }
        
        return dp[n - 1];
    }
};