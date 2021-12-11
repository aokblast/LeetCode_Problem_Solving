//
//Runtime 112
//Memory Usage 91.7
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<bool> visit(n);
        for(int i = 0; i < n; ++i){
            if(visit[i])continue;
            int idx = i, cnt = 0;
            do{
                visit[idx] = true;
                ++cnt;
                idx = nums[idx];
            }while(idx != i);
            res = max(res, cnt);
        }
        return res;
    }
};
