//
//Runtime 4
//Memory Usage 13.5
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time(timePoints.size());
        int h, m, i = 0;
        
        for(const string &t : timePoints){
            h = (t[0] - '0') * 10 + t[1] - '0';
            m = (t[3] - '0') * 10 + t[4] - '0';
            time[i++] = (h * 60 + m);
        }
        sort(time.begin(), time.end());
        int ans = INT_MAX;
        for(int i = 1; i < time.size(); ++i){
            ans = min(ans, time[i] - time[i - 1]);
        }
        ans = min(ans, time[0] + 1440 - time[time.size() - 1]);
        return ans;
    }
};
