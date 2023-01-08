//
//Runtime 18
//Memory Usage 10.2

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coords) {
        int n = coords.size();
        
        
        for(int i = 2; i < n; ++i) {
            auto &p1 = coords[i - 2], &p2 = coords[i - 1], &p3 = coords[i];
            
            if((p1[0] - p2[0]) * (p2[1] - p3[1]) != (p2[0] - p3[0]) * (p1[1] - p2[1]))
                return false;
        }
            
        return true;
    }
};