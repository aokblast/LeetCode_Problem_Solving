//
//Runtime 32
//Memory Usage 28.2
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mi = INT_MAX;
        int ans = 0;
        for(int &n : nums){
            mi = min(mi, n);
        }
        for(int &n : nums){
            ans += (n - mi);
        }
        return ans;
    }
};
