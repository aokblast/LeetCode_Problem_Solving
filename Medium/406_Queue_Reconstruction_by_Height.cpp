//
//Runtime 132
//Memory Usage 12.1
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [](vector<int> &p1, vector<int> &p2)->bool{return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);});
        vector<vector<int>> res;
        for(vector<int> &pu : p){
            res.insert(res.begin() + pu[1], pu);
        }
        return res;
    }
};
