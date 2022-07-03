//Greedy
//Runtime 3
//Memory Usage 10

class Solution {
public:
    bool sort[105] = {false};
    int minDeletionSize(vector<string>& strs) {
        int res = 0, n = strs.size(), m = strs[0].size();
        for(int i = 0; i < m; ++i){
            int j;
            for(j = 0; j < n - 1; ++j){
                if(!sort[j] && (strs[j][i] > strs[j + 1][i])){
                    ++res;
                    break;
                }
            }
            
            if(j < n - 1)
                continue;
            
            for(int j = 0; j < n - 1; ++j)
                sort[j] |= strs[j][i] < strs[j + 1][i];
        }
        return res;
    }
};