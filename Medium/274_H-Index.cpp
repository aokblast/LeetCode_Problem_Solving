//preSum
//Runtime 0
//Memory Usage 8.6
class Solution {
public:
    int c[5005] = {0};
    int preSum[5005] = {0};
    int hIndex(vector<int>& citations) {
        int ma = 0;
        for(auto num : citations){
            ++c[num];
            ma = max(ma, num);
        }
        for(int i = 1; i <= ma; ++i){
            preSum[i] = preSum[i - 1] + c[i];
        }
        for(int i = ma; i >= 1; --i){
            if((preSum[ma] - preSum[i - 1]) >= i){
                return i;
            }
        }
        return 0;
    }
};
