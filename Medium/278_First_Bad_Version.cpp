//Binary Search
//Runtime 0
//Memory Usage 18.7
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1, right = n;
        while(left < right){
            long long mid = (left + right) >> 1;
            if(isBadVersion(mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return (int)right;
    }
};
