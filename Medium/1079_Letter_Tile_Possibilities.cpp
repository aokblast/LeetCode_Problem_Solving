//dfs
//Runtime 4
//Memory Usage 6

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size(), res = 0;
        
        sort(tiles.begin(), tiles.end());
        
        
        function<void(string, int)> dfs = [&](string tiles, int idx) {
            ++res;
            for(int i = idx; i < n; ++i) {
                if(i != idx && tiles[i] == tiles[idx])
                    continue;
                swap(tiles[i], tiles[idx]);
                dfs(tiles, idx + 1);
            }
        };
        
        dfs(tiles, 0);
        return res - 1;
        
        
    }
};



