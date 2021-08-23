//map + binary_search
//Runtime 40
//Memory Usage 18.6
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int size = nums.size();
        int j = 0;
        for(int i = 0; i < size; ++i){
            if((i - j) > k) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if(a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
//sort
//Runtime 20
//Memory Usage 17.2
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int size = nums.size();
        int j = 0;
        for(int i = 0; i < size; ++i){
            if((i - j) > k) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if(a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
