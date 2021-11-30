//DP
//Runtime 7
//Memory Usage 42.1

class Solution {


    public int[][] updateMatrix(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int [][]res = new int[n][m];
        int max = Integer.MAX_VALUE - 20000;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 0)continue;
                res[i][j] = max;
                if(i >= 1)res[i][j] = Math.min(res[i][j], res[i - 1][j] + 1);
                if(j >= 1)res[i][j] = Math.min(res[i][j], res[i][j - 1] + 1);
            }
        }

        for(int i = n - 1; i >= 0; --i){
            for(int j = m - 1; j >= 0; --j){
                if(i <= n - 2)res[i][j] = Math.min(res[i][j], res[i + 1][j] + 1);
                if(j <= m - 2)res[i][j] = Math.min(res[i][j], res[i][j + 1] + 1);
            }
        }

        return res;
    }
}
