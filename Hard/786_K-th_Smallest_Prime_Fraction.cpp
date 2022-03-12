//Binary Search
//Runtime 8
//Memory Usage 8.1

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size(), p = 0, q = 1;
        double l = 0, r = 1;
        while(true){
            int cnt = 0, p = 0;
            double mid = l + (r - l)  / 2.0;
            for(int i = 0, j = 0; i < n; ++i){
                while(j < n && arr[i] > arr[j] * mid)
                    ++j;
                cnt += n - j;
                if(j < n && p * arr[j] < q * arr[i])
                    p = arr[i], q = arr[j];

            }
            if(cnt == k)
                return {p, q};
            else if(cnt > k)
                r = mid;
            else
                l = mid;
            
        }
        return {0, 0};
        
    }
};