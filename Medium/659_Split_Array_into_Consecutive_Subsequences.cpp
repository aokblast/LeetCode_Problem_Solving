//
//Runtime 92
//Memory Usage 58.4

class Solution {
public:
    unordered_map<int, int> frq, dui;
    bool isPossible(vector<int>& nums) {
        for(const int num : nums)
            ++frq[num];
        for(int num : nums){
            if(frq[num] == 0)
                continue;
            if(dui[num])
                --dui[num], ++dui[num + 1];
            else if(frq[num + 2] > 0 && frq[num + 1] > 0)
                --frq[num + 1], --frq[num + 2], ++dui[num + 3];
            else return false;
            --frq[num];
        }
        return true;
    }
};