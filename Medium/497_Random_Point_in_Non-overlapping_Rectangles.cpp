//Reservoir sampling
//Runtime 80
//Memory Usage 68.5
class Solution {
public:
    Solution(vector<vector<int>>& rects): rec(rects) {
        
    }
    
    vector<int> pick() {
        vector<int> v;
        int sum = 0;
        for(vector<int> &ve : rec){
            int area = (ve[3] - ve[1] + 1) * (ve[2] - ve[0] + 1);
            sum += area;
            if(rand() % sum < area) v = ve;
        }
        return vector<int>({(rand() % (v[2] - v[0] + 1)) + v[0], (rand() % (v[3] - v[1] + 1)) + v[1] });
    }
    vector<vector<int>>rec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
