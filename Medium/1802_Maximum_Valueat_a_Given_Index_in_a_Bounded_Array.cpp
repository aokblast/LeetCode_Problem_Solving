//Binray Search
//Runtime 0
//Memory Usage 5.8

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int l = 0, r = maxSum, l_num  = index + 1, r_num = n - index;
        
        while(l < r) {
            long mid = (l + r + 1) / 2;

            long left_min = mid - index;
            long right_min = mid - (n - index) + 1;
            long sum = -mid;

            if(left_min <= 0) {
                sum += mid * (mid + 1) / 2;
            } else {
                sum += (mid + left_min) * l_num / 2;
            }

            if(right_min <= 0) {
                sum += mid * (mid + 1) / 2;
            } else {
                sum += (mid + right_min) * r_num / 2;
            }

            if(sum <= maxSum)
                l = mid;
            else if(sum > maxSum)
                r = mid - 1;
        }

        return l + 1;
    }
};