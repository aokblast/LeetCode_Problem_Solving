//
//Runtime 3
//Memory Usage 10.4
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0] - points[1][0], y1 = points[0][1] - points[1][1], x2 = points[1][0] - points[2][0], y2 = points[1][1] - points[2][1];
        function<int(int, int)> gcd = [&](int x, int y){
            return y == 0 ? x : gcd(y, x % y);  
        };
        int d1 = gcd(x1, y1), d2 = gcd(x2, y2);
        return (points[0] != points[1] && points[1] != points[2]) && !( x1 / d1 == x2 / d2 && y1 / d1 == y2 / d2);
        
    }
};