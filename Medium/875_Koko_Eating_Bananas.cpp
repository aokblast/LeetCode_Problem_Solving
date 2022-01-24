//Binary Search
//Runtime 58
//Memory Usage 18.9


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9;
        while(left < right){
            int mid = left + ((right - left) >> 1) , cnt = 0;
            for(const int pile : piles) cnt += (pile + mid - 1) / mid;
            if(cnt > h)left = mid + 1; 
            else right = mid;
        }
        return left;
    }
};