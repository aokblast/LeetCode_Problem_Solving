//
//Runtime 4
//Memory Usage 13.9

class Solution {
public:
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    int vis[50][50] = {0};
    int m, n;
    void dfs(vector<vector<int>> &img, int x, int y, int col, int ncol){
        if(x < 0 || y < 0 || x >= m || y >= n || vis[x][y] || img[x][y] != col)
            return;
        img[x][y] = ncol;
        for(int i = 0; i < 4; ++i)
            dfs(img, x + dir[i][0], y + dir[i][1], col, ncol);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        m = image.size(), n = image[0].size();
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};