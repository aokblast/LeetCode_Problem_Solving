//
//Runtime 80 
//Memory Usage 27.2 
class Solution {
public:
    double x, y, r;
    Solution(double radius, double x_center, double y_center) : x(x_center), y(y_center), r(radius){
        
    }
    
    vector<double> randPoint() { 
        double R = r  * sqrt((double)rand() / RAND_MAX);
        double theta = M_PI * 2 * (double)rand() / RAND_MAX;
        return {x + R * cos(theta), y + R * sin(theta)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
