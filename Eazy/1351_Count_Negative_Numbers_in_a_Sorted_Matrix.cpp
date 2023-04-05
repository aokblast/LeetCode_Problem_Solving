//
//Runtime 13
//Memory Usage 10.5

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;

        for(int i = m - 1; i >= 0; --i) 
            if(grid[n - 1][i] < 0)
                for(int j = n - 1; j >= 0; --j) 
                    if(grid[j][i] < 0)
                        ++res;
                    else
                        break;
            else
                break;

        return res;
    }
};