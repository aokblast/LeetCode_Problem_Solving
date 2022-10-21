//Binary Search
//Runtime 7
//Memory Usage 7.1
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1, peak;
        while(l < r) {
            int mid = l + (r - l) / 2;
            int a = -1, b = -1, c = -1;
            b = mountainArr.get(mid);
            if(mid - 1 >= 0)
                a = mountainArr.get(mid - 1);
            if(mid + 1 < n)
                c = mountainArr.get(mid + 1);
            if((mid == 0 || a <= b) && (mid == n - 1 || b >= c)) {
                peak = mid;
                break;
            }
            if(mid == 0 || a <= b)
                l = mid + 1;
            else
                r = mid;
        }
        l = 0, r = peak;
        int res = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);
            if(val > target) {
                r = mid - 1;
            }else if(val < target) {
                l = mid + 1;
            }else {
                res = mid;
                break;
            }
        }
        if(res == -1) {
            l = peak + 1, r = n - 1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                int val = mountainArr.get(mid);
                if(val < target) {
                    r = mid - 1;
                }else if(val > target) {
                    l = mid + 1;
                }else {
                    res = mid;
                    break;
                }
            }
        }
        return res;
        
    }
};