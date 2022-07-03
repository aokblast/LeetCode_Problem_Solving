//Rolling Window
//Runtime 63
//Memory Usage 42.4

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lim = n - k - 1;
        int sum = 0, res = INT_MAX, l = 0, r = 0, cur = 0;
        if(lim == -1)
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        while((r - l) < lim)
            sum += cardPoints[r], cur += cardPoints[r++];
        ++lim;
        while(r < n){
            sum += cardPoints[r], cur += cardPoints[r++];
            res = min(res, cur);
            cur -= cardPoints[l++];   
        }
        return sum - res;
    }
};