//
//Runtime 0
//Memory 6.9
class Solution {
public:
    bool visit[10][10];
    int dir[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int x = 0, y = 0;
        int d = 0;
        for(int i = 0; i < m * n; ++i){
            result.push_back(matrix[x][y]);
            visit[x][y] = true;
            int next_x = x + dir[d][0], next_y = y + dir[d][1];
            if(next_y == n || next_y == -1 || next_x == m || next_x == -1 || visit[next_x][next_y])++d;
            d %= 4;
            x += dir[d][0], y += dir[d][1];
        }
        
        return result;
    }
};
