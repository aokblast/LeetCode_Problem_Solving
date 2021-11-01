//
//Runtime 0 
//Memory Usage 6.2
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int mid = sqrt(area);
        while(area % mid) --mid;
        return {area / mid, mid};
    }
};
