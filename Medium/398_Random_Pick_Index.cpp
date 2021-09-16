//Reservior Sampling
//Runtime 60 
//Memory Usage 35.6
class Solution {
public:
    vector<int> n;
    Solution(vector<int>& nums) {
        n = nums;
    }
    
    int pick(int target) {
        int size = n.size(), cnt = 0, ans = 0;
        for(int i = 0; i < size; ++i){
            if(n[i] != target) continue;
            ++cnt;
            if(!(rand() % cnt)) ans = i;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
