//sort
//Runtime 20
//Memory Usage 15.3
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size=  nums.size();
        unordered_set<int> s;
        
        
        for(int i = 0; i < size; ++i){
            if(s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
