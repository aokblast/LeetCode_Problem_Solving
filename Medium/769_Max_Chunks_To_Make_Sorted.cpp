//Greedy
//Runtime 0
//Memory Usage 7.3

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int curSum = 0, tSum = 0, res = 0;
        for(int i = 0; i < arr.size(); ++i){
            curSum += arr[i];
            tSum += i;
            res += curSum == tSum;
        }
        return res;
    }
};