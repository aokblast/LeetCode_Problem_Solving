//
//Runtime 52 
//Memory Usage 31.9
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> res;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<int> newInt = {val, val};
        int n = res.size();
        int i = 0, cnt = 0;
        for(i; i < n; ++i){
            if(newInt[1] + 1 < res[i][0]) break;
            if(newInt[0] <= res[i][1] + 1){
                newInt[0] = min(newInt[0], res[i][0]);
                newInt[1] = max(newInt[1], res[i][1]);
                ++cnt;
            }
        }
        if(cnt)res.erase(res.begin() + i - cnt, res.begin() + i);
        res.insert(res.begin() + i - cnt, newInt);
    }
    
    vector<vector<int>> getIntervals() {
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
