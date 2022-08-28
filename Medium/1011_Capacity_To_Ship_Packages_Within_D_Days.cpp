//Binary Search
//Runtime 50
//Memory Usage 26.1

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = accumulate(weights.begin(), weights.end(), 0);
        
        auto countDays = [&](int lim){
            int res = 1, cur = 0;
            for(const int w : weights) 
                if(w + cur > lim)
                    ++res, cur = w;
                else
                    cur += w;
            return res;
        };
        
        while(l < r){
            int mid = l + (r - l) / 2;
            if(countDays(mid) <= days)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};