//Greedy
//Runtime 52
//Memory Usage 61.5

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int little = INT_MAX, mid = INT_MAX;
        for(int &num : nums){
            if(little >= num) little = num;
            else if (mid >= num) mid = num;
            else return true;
        }
        return false;
    }
};
