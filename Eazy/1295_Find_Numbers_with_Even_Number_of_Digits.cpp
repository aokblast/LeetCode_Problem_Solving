//
//Runtime 4
//Memory Usage 9.9
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;

        for(const int num : nums) 
            res += to_string(num).size() % 2 == 0;
        
        return res;
    }
};