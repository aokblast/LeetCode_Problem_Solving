//dp
//Runtime 28
//Memory Usage 8.2

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int res = 0, n = arr.size();
        
        vector<unsigned> used;
        
        unsigned invalid = 0;
        
        for(int i = 0; i < n; ++i) {
            const auto &s = arr[i];
            unsigned status = 0;
            for(const char c : s) {
                if(status & (1 << (c - 'a'))) {
                    invalid |= (1 << i);
                    break;
                }
                status |= 1 << (c - 'a');
            }
            used.push_back(status);
        }
        
        
        for(int i = 0; i < (1 << n); ++i) {
            bool legal = true;
            unsigned cur = 0;
            int len = 0;
            if(i & invalid)
                continue;
            for(int mask = 0; mask < n; ++mask) {
                if(i & (1 << mask)) {
                    if(cur & used[mask]) {
                        legal = false;
                        break;
                    }
                    cur |= used[mask];
                    len += arr[mask].size();
                }
            }
            if(legal)
                res = max(res, len);
        }
        return res;
    }
};