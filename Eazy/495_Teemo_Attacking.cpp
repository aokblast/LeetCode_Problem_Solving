//
//Runtime 20
//Memory Usage 25.8

static const auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int n = timeSeries.size();
        for(int i = 0; i < n - 1; ++i){
            ans += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        ans += duration;
        return ans;
    }
};
