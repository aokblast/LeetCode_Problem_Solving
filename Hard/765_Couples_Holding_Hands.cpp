//
//Runtime 0
//Memory Usage 7.4
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        int n = row.size();
        for(int i = 0; i < n - 1; ++i){
            if(row[i] != (row[i + 1] ^ 1)){
                for(int j = i + 1; j < n; ++j){
                    if((row[j] ^ 1) == row[i]){
                        ++res;
                        swap(row[j], row[i + 1]);
                    }
                } 
            }

        }
        return res;
    }
};