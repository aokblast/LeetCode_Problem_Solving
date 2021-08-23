//hash_map
//Runtime 0 
//Memory Usage 6
class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0;
        int size = columnTitle.size();
        for(int i = 0; i  < size; ++i){
            result = result * 26 + (columnTitle[i] - 'A' + 1);
        }
        return result;
    }
};
