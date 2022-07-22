//Greedy
//Runtime 39
//Memory Usage 18.8

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        
        
        int l = 0, r = 0;
        while(l < firstList.size() && r < secondList.size()){
            int a = max(firstList[l][0], secondList[r][0]);
            int b = min(firstList[l][1], secondList[r][1]);
            if(a <= b)
                res.emplace_back(vector({a, b}));
            
            if(firstList[l][1] < secondList[r][1])
                ++l;
            else if(firstList[l][1] > secondList[r][1])
                ++r;
            else
                ++l, ++r;
            
        }
        return res;
    }
};