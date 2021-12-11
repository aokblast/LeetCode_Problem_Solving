//
//Runtime 0 
//Memory Usage 7.3 
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ji = 0, ou = 0;
        for(const int &num : position){
            if(num % 2)++ji;
            else ++ou;
        }
        return min(ji, ou);
    }
};
