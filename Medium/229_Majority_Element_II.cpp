//Moore Algorithm
//Runtime 7
//Memory Usgae 15.8
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0;
        vector<int> ans;
        for(int &num : nums){
            if(num == num1) ++cnt1;
            else if(num == num2) ++cnt2;
            else if(cnt1 == 0) num1 = num, cnt1 = 1;
            else if(cnt2 == 0) num2 = num, cnt2 = 1;
            else (--cnt1, --cnt2);
            
        }
        cnt1 = cnt2 = 0;
        for(int &num : nums){
            if(num1 == num)++cnt1;
            else if(num2 == num)++cnt2;
        }
        int t = nums.size() / 3;
        if(cnt1 > t) ans.push_back(num1);
        if(cnt2 > t) ans.push_back(num2);
        return ans;
    }
};
