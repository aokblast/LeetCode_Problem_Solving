//
//Runtime 0
//Memory Usage 6.4
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        vector<int> result, tmp;
        while(rowIndex--){
            tmp.push_back(1);
            for(int i = 0; i < ((int)(result.size())) - 1; ++i){
                tmp.push_back(result[i] + result[i + 1]);
            }
            tmp.push_back(1);
            result.swap(tmp);
            tmp.clear();
        }
        return result;
        
    }
};
