//bfs
//Runtime 78
//Memory Usage 20.1

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       	sort(nums.begin(), nums.end());
        int res = 1e5;
        
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            int cur = nums[i];
            int l = i + 1, r = n - 1;
            
            while(l < r) {
                int sum = cur + nums[l] + nums[r];
                
                if(abs(target - res) > abs(target - sum))
                    res = sum;
                
                if(target - sum > 0)
                    l++;
                else
                    r--;
            }
        }
        return res;
        

    }
};