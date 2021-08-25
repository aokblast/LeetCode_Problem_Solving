//deque
//Runtime 168 
//Memory Usage 135.1
class Solution {
public:
    vector<int> ans; 
    deque<int> deq;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        for(int i = 0; i < nums.size(); ++i){
            if(!deq.empty() && deq.front() == i - k) deq.pop_front();
            while(!deq.empty() && nums[deq.back()] < nums[i]) deq.pop_back();
            deq.push_back(i);
            if(i >= k - 1) ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};
//multiset
//Runtime 528
//Memory usage 210
