//
//Runtime 34
//Memory Usage  8.5
class Solution {
public:
    struct Point {
        double x, y;
        Point(double x, double y) : x(x), y(y){}
    };
    int numPoints(vector<vector<int>>& darts, int r) {
        int n = darts.size(), res = 1;

        auto dist = [](const Point &d1, const Point &d2) {
            const double x = d1.x - d2.x, y = d1.y - d2.y;
            return sqrt(x * x + y * y);
        };

        auto getMid = [&](const Point &d1, const Point &d2) {
            Point mid((d1.x + d2.x) / 2.0, (d1.y + d2.y) / 2.0);

            auto angle = atan2(d1.y - d2.y, d2.x - d1.x);
            auto d = sqrt(r * r - pow(dist(mid,  d1), 2));

            return Point(mid.x + d * sin(angle), mid.y + d * cos(angle));
        };

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                Point P1(darts[i][0], darts[i][1]);
                Point P2(darts[j][0], darts[j][1]);

                if(dist(P1, P2) > 2 * r) 
                    continue;

                int cnt = 0;
                auto mid = getMid(P1, P2);

                for(int k = 0; k < n; ++k) 
                    if(dist(mid, Point(darts[k][0], darts[k][1])) <= r + 1e-9)
                        ++cnt;
                
                res = max(res, cnt);
            }
        }
        
        return res;
    }
};