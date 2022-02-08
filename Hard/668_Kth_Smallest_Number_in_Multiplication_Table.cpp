//binary Search
//Runtime 12
//Memory Usage 6

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while(l < r){
            int mid = l + ((r - l) >> 1);
            int acc = 0;
            for(int i = 1; i <= n; ++i)
                acc += min(mid / i, m);
            if(acc >= k)
                r = mid;
            else 
                l = mid + 1;
        }
        return r;
    }
};