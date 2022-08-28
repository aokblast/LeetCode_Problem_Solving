//
//Runtime 45
//Memory Usage 17.4
struct T{
    int x, y, dis;
    T() = default;
    bool operator<(const T &t) const {
        return dis < t.dis;
    }
};

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {

        vector<vector<int>> res;
        vector<T> v(rows * cols);

        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                v[i * cols + j] = {i, j, abs(i - rCenter) + abs(j - cCenter)};
            

        sort(v.begin(), v.end());
        
        for(const auto [x, y, dis] : v)
            res.push_back({x, y});
        
        return res;
    }
};