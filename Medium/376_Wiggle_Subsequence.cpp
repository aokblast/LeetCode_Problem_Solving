//DP
//Runtime 0
//Memory Usage 7.1

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)return 1;
        int tmp, tmp2, size = nums.size(), total = 0, mode = 0, result = 1;
        for(int i = 1; i < size; ++i){
            tmp = nums[i -1];
            tmp2 = nums[i];
            switch (mode){
                case 0:
                    if(tmp2 != tmp){
                        mode = ((tmp2 - tmp) > 0) ? 1 : -1;
                        ++result;
                    }
                    break;
                case 1:
                    if(tmp > tmp2){
                        mode = -1;
                        ++result;
                    }
                    break;
                case -1:
                    if(tmp2 > tmp){
                        mode = 1;
                        ++result;
                    }break;
                
                    
                    
            }
        }
        
        
        
        return result;
    }
};
