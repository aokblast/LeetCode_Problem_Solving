//Binary Search
//Runtime 165
//Memory Usage 66.6

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < ((long) m * k))
            return -1;

        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());

        while(l < r) {
            int mid = l + (r - l) / 2;
            int sum = 0, cur = 0;
        
            for(const auto bloom: bloomDay) {
                if(bloom > mid)
                    cur = 0;
                else {
                    if(++cur == k) {
                        if(++sum == m)
                            break;
                        cur = 0;
                    }
                }
            }

            if(sum < m)
                l = mid + 1;
            else
                r = mid;
        }

        return r;
    }
};