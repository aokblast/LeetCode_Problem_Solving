//Greedy
//Runtime 68
//Memory Usage 25.8

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> t(n);
        int res = 0;

        for(int i = 0; i < n; ++i) {
            int cur = 0;
            for(int j = n - 1; j >= 0; --j) {
                if(grid[i][j] == 0)
                    ++cur;
                else
                    break;
            }
            t[i] = cur;   
        }

        for(int i = 0; i < n; ++i) {
            int cur = i;
            int req = n - 1 - i;
            while(cur < n && t[cur] < req)
                ++cur;
            if(cur == n)
                return -1;

            res += cur - i;

            for(int j = cur - 1; j >= i; --j)
                t[j + 1] = t[j];

        }

        return res;
    }
};