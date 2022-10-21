//
//Runtime 52
//Memory Usage 23

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0, n = hours.size(), cnt = 0;
        
        unordered_map<int, int> mp;        

        for(int i = 0; i < n; ++i) {
            cnt += hours[i] > 8 ? 1 : -1;
            
            if(cnt > 0) {
                res = max(res, i + 1);
            } else {
                if(!mp.count(cnt))
                    mp[cnt] = i;
                if(mp.count(cnt - 1))
                    res = max(res, i - mp[cnt - 1]);
            }
            
        }
        return res;

    }
};