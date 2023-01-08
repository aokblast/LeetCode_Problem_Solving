//Binary Search
//Runtime 14
//Memory Usage 12.3

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int l = 0, r = *max_element(arr.begin(), arr.end());

        while(l + 1< r) {
            int mid = l + (r - l) / 2;
            int acc = 0;

            for(const int num : arr)
                acc += min(num, mid);

            if(acc < target)
                l = mid;
            else
                r = mid;
        }

        int ls = 0, rs = 0;

        for(const int num : arr)
            ls += min(num, l), rs += min(num, r);

        if(abs(target - ls) <= abs(target - rs))
            return l;
        else
            return r;

        return l;
    }
};