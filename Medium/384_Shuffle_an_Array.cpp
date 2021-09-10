//
//Runtime 92 
//Memory Usage 90.3
class Solution {
public:
    vector<int> now, orig; 
    Solution(vector<int>& nums) {
        now = orig = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return now = orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = 0; i < now.size(); ++i){
            swap(now[i], now[rand() % now.size()]);
        }
        return now;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
