//Binary Search
//Runtime 243
//Memory Usage 94.5

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 100000000000000;

        while(l < r) {
            long long mid = l + (r - l) / 2;
            long long cur = 0;

            for(const auto t : time) {
                cur += mid / t;
                if(cur >= totalTrips)
                    break;
            }

            if(cur >= totalTrips)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};