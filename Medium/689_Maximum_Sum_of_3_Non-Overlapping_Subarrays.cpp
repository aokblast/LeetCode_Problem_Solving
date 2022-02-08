//
//Runtime 28
//Memory Usage 23.3
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int ma = INT_MIN, n = nums.size();
        
        vector<int> sums{0}, res, left(n, 0), right(n, n - k);
        
        for (int num : nums) 
            sums.push_back(sums.back() + num);
        
        for(int i = k, total = sums[k] - sums[0]; i < n; ++i){
            if(sums[i + 1] - sums[i + 1 - k] > total){    
                left[i] = i + 1 - k;
                total = sums[i + 1] - sums[i + 1 - k];
            }else{
                left[i] = left[i - 1];
            }
            
        }
        
        for(int i = n - k - 1, total = sums[n] - sums[n - k]; i >= 0; --i){
            if(sums[i + k] - sums[i] >= total){
                right[i] = i;
                total = sums[i + k] - sums[i];
            }else{
                right[i] = right[i + 1]; 
            }
            
        }
        
        for(int i = k; i <= n - 2 * k; ++i){
            int l = left[i - 1], r = right[i + k];
            int total = (sums[l + k] - sums[l]) + (sums[i + k] - sums[i]) + (sums[r + k] - sums[r]);
            
            if(ma < total){
                ma = total;
                res = {l, i, r};
            }
        }
        return res;
    }
};