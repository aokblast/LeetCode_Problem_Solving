//
//Runtime 2
//Memory Usage 8.2

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> res(5);
        res[0] = INT_MAX;
        long pfsum[256] = {0};
        long cnt = 0, mostNumber = 0;
        
        for(int i = 0; i <= 255; ++i) {
            if(count[i]) {
                res[0] = min(res[0], (double)i);
                res[1] = max(res[1], (double)i);
                res[2] += (long)i * count[i];
                cnt += count[i];
                if(mostNumber < count[i])
                    res[4] = i, mostNumber = count[i];
            }
            pfsum[i] = cnt;
        }
        int idx = lower_bound(pfsum, pfsum + 256, (cnt + 1) / 2) - pfsum;
        int next = idx + 1;
         
        while(cnt % 2 == 0 && pfsum[next] == pfsum[next - 1])
            ++next;
        
        res[3] = !(cnt % 2) ? (pfsum[idx] == (cnt / 2) ? (next + idx) / 2.0  : idx) : idx;
        res[2] /= cnt;
        return res;
    }
};