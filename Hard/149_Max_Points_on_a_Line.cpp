//hash_map
//Runtime 8
//Memory Usage 8.9

class Solution {
    
public:

    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return 1;
        int size = points.size();
        int ans = 0;
        for(int i  = 0; i < size; ++i){
            map<pair<int, int>, int> count;
            for(int j = i + 1; j < size; ++j){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int fenMu = gcd(dx, dy);
                auto p = make_pair(dx / fenMu, dy / fenMu);
                ++count[p]; 
            }
            for(auto iter : count){
                ans = max(ans, iter.second + 1);
            }
        }

        return ans;
    }
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
};
