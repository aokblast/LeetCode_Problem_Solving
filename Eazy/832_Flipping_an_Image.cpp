//
//Runtime 4
//Memory Usage 8.8
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &row : image){
            reverse(row.begin(), row.end());
            for(int &i : row)
                i ^= 1;
        }
        return image;
    }
};