// 
//Runtime 16
//Memory Usage 7.7

class Solution {
public:
    using pa = vector<int>; 
    double line(pa &p1, pa &p2){
        return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] -p2[1]) * (p1[1] - p2[1]));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                for(int k = j + 1; k < n; ++k){
                    double l1 = line(points[i], points[j]), l2 = line(points[j], points[k]), l3 = line(points[k], points[i]);
                    if(l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1){
                        double s = 0.5 * (l1 + l2 + l3);
                        res = max(res, sqrt(s * (s - l1) * (s - l2) * (s - l3)));
                    }
                }
            }
        }
        return res;
    }
};