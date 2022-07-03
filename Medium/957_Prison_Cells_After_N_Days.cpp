//Math
//Runtime 3
//Memory Usage 12

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> tmp(cells.size());
        int num = n % 14 == 0 ? 14 : n % 14;
        while(num--){
            for(int i = 1; i < 7; ++i)
                tmp[i] = !(cells[i - 1] ^ cells[i + 1]);
            for(int i = 0; i < 8; ++i)
                cells[i] = tmp[i];
        }
        return cells;
    }
};