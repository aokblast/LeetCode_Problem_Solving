//Binary Search
//Runtime 12
//Memory Usage 8

class Solution {
    double dist(const vector<int> &a, const vector<double> &b) {
        return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
    }
    double all_dist(const vector<vector<int>> &pos, vector<double> &p) {
        double res = 0;
        for(const auto &pa : pos)
            res += dist(pa, p);
        return res;
    }
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        constexpr int dirs[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        double res = DBL_MAX;
        vector<double> cur(2, 0);
        double step = 100, eps = 1e-6;
        while(step > eps) {
            bool found = false;
            for(const auto &d: dirs) {
                vector<double> next = {cur[0] + step * d[0], cur[1] + step * d[1]};
                double dis = all_dist(positions, next);
                if(dis < res) {
                    res = dis;
                    cur = next;
                    found = true;
                    break;
                }
            }
            if(!found)
                step /= 2;
        }
        return res;
    }
};