//Greedy
//Runtime 298
//Memory Usage 110.2

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int n = rains.size();
        vector<int> res(n, -1);
        set<int> rem;
        unordered_map<int, int> last;
        
        for(int i = 0; i < n; ++i) {
            int cur = rains[i];
            if(cur == 0) {
                rem.insert(i);
                res[i] = 1;
            } else {
                if(last.count(cur)) {
                    auto iter = rem.lower_bound(last[cur]);
                    if(iter == rem.end())
                        return {};
                    res[*iter] = cur;
                    rem.erase(iter);
                    
                } 
                last[cur] = i;
            }
        }
        
        return res;
    }
};