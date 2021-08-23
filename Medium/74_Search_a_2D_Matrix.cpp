//Binary Search
//Runtime 0
//Memory Usage 9.5
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1;
        while(left <= right){
            int mid = (left + right) >> 1;
            int val = matrix[mid / m][mid % m];
            if(val  > target){
                right = mid - 1;
            }else if(val < target){
                left = mid + 1;
            }else{
                return true;
            }
        }
        return false;
    }
};
