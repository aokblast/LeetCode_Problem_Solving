//Set
//Runtime 104 
//Memory Usage 32.2
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int, int>> c;
        int area = 0;
        for(const vector<int> &rect : rectangles){
            pair<int, int> p1{rect[0], rect[1]};
            pair<int, int> p2{rect[2], rect[1]};
            pair<int, int> p3{rect[2], rect[3]};
            pair<int, int> p4{rect[0], rect[3]};
            for(const pair<int, int> &p : {p1, p2, p3, p4}){
                const auto& ret = c.insert(p);
                if(!ret.second)c.erase(ret.first);
                
            }
            area += (p1.first - p3.first) * (p1.second - p3.second);
        }
        if(c.size() != 4)return false;
        const auto& p1 = *c.begin();
        const auto& p3 = *c.rbegin();
        return area == (p3.first - p1.first) * (p3.second - p1.second);
        
    }
};
