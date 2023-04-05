//Sliding Window
//Runtime 78
//Memory Usage 55.5

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        
        int cur = 0, res = 0;
        threshold *= k;

        for(int i = 0; i < k; ++i) 
            cur += arr[i];
        res += cur >= threshold;

        for(int i = k; i < n; ++i) 
            cur += arr[i], cur -= arr[i - k], res += cur >= threshold;

        return res;
    }
};