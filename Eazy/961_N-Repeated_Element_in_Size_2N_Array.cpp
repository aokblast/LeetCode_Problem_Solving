//
//Runtime 45
//Memory Usage 24.6
class Solution {
public:
    bool find[10005] = {false};
    int repeatedNTimes(vector<int>& nums) {
        for(const int num : nums)
            if(find[num])
                return num;
            else
                find[num] = true;
        return 0;
    }
}