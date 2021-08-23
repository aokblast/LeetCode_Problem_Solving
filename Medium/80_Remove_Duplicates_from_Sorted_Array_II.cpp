//
//Runtime 0
//Memory Usage 11
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0;
        int Ind = 1;
        for(int j = 1; j < size; ++j){
            if(nums[j] == nums[j- 1]){
                cnt++;
                if(cnt < 2){
                    nums[Ind++] = nums[j];
                }
            }
            else{
                cnt = 0;
                nums[Ind++] = nums[j];
            }
        }
        return Ind;
    }
};
