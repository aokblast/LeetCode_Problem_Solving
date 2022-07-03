//
//Runtime 51
//Memory Usage 16
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const auto &b1, const auto &b2){return b1[1] == b2[1] ? b1[0] > b2[0] : b1[1] > b2[1];});
        
        int cur = 0, res = 0;
        
        for(const auto &box : boxTypes){
            cur = min(truckSize, box[0]), res += cur * box[1], truckSize -= cur;
            if(!truckSize)
                break;
        }
        
        return res;
        
        
        
    }
};