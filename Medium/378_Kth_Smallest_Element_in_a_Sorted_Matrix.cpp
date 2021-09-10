//Binary Search
//Runtime 22 
//Memory Usage 13.1
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while(left < right){
            int mid = left + ((right - left) >> 1);
            int cnt = 0;
            for(vector<int> &line : matrix){
                cnt += upper_bound(line.begin(), line.end(), mid) - line.begin();
            }

            if(cnt < k) left = mid +1;
            else right = mid;
        }
        return left;
    }
};
