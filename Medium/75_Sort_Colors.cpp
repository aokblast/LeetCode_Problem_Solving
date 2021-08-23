//Bucket Sort
//Runtime 0
//Memory Usage 8.3
class Solution {
public:
    int arr[3];
    void sortColors(vector<int>& nums) {
        for(int &i : nums) ++arr[i];
        int top  = 0;
        for(int i = 0; i < nums.size(); ++i){
            while(arr[top] == 0)++top;
            nums[i] = top;
            --arr[top];
        }
    }
};
