//DAC
//Runtime 72
//Memory Usage 14.9

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0;
        int y = matrix.size() - 1;
        int max = matrix[0].size();
        int cache = 0;
        while(1){
              if(x == max || y == -1) return false;
              cache = matrix[y][x];
              if(cache == target) return true;
              else if(cache > target) --y;
              else if(cache < target) ++x;
        }
    }
};

//Binary Search
//Runtime 272
//Memory Usage 14.7
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       for(auto &line : matrix){
       		if(binary_search(line.begin(), line.end(),target)) return true;
           if(line[0] > target) return false;
       }
       return false;
    }
};
