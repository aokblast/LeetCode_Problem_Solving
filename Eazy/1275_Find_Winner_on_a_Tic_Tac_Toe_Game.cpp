//
//Runtime 3
//Memory Usage 8.3
class Solution {
public:
    
    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        int grid[3][3];

        memset(grid, ' ', sizeof(grid));

        for(int i = 0; i < n; ++i) {
            char cur = grid[moves[i][0]][moves[i][1]] = i % 2 ? 'B' : 'A';
            bool ans = true;

            for(int x = 0; x < 3; ++x) 
                ans &= grid[x][moves[i][1]] == cur;

            if(ans)
                return string() + cur;
            else
                ans = true;

            for(int y = 0; y < 3; ++y)
                ans &= grid[moves[i][0]][y] == cur;

            if(ans)
                return string() + cur;
            else
                ans = true;
            
            for(int a = 0; a < 3; ++a) 
                ans &= grid[a][a] == cur;
                
            if(ans)
                return string() + cur;
            else
                ans = true;

            for(int a = 0; a < 3; ++a) 
                ans &= grid[a][2 - a] == cur;
                
            if(ans)
                return string() + cur;
            else
                ans = true;
        }
        

        return n == 9 ? "Draw" : "Pending";
    }
};