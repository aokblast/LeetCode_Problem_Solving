//dp
//Runtime 7
//Memory Usage 6

class Solution {
public:
    double cur[25][25] = {0}, pre[25][25] = {0};
    int dir[8][2] = {2, 1, 1, 2, 2, -1, -1, 2, -2, 1, 1, -2, -1, -2, -2, -1};
    double knightProbability(int n, int k, int row, int column) {
        pre[row][column] = 1.0;

        while(k--){
            memset(cur, 0, sizeof(cur));
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    double val = pre[i][j] / 8.0;
                    for(int k = 0; k < 8; ++k){
                        int ii = i + dir[k][0], jj = j + dir[k][1];
                        if(ii < 0 || jj < 0 || ii >= n || jj >= n)
                            continue;
                        cur[ii][jj] += val;
                    }
                    
                }
            }
            memcpy(pre, cur, sizeof(cur));
        }
        double res = 0.0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                res += pre[i][j];
            }
        }
        
        return res;
    }
};