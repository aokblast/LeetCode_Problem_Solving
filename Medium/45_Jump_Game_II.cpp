//Greedy
//Runtime 12
//Memory Usage 16.3


class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        int step = 0;
        int fur = 0;
        int tmp = 0;
        for(int i = 0; i < length && fur < length - 1; ){
            while(i <= fur){
                tmp = max(tmp ,  i + nums[i]);
                ++i;
            }
            fur = tmp;
            ++step;
        }
        return step;
    }
};
