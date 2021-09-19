//
//Runtime 392
//Memory Usage 89.9
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0, n = intervals.size(), last = intervals[0][1];
        
        for(int i = 1; i < n; ++i){
            if(intervals[i][0] < last){
                ++ans;
                if(intervals[i][1] < last)last = intervals[i][1];
            }else{
                last = intervals[i][1];
                
            }
        }
        return ans;
    }
};
