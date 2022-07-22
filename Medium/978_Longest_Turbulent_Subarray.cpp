//
//Runtime 73
//Memory Usage 40.3s

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1, mode = 0, n = arr.size();
        
        int l = 1, r = 1;
        
        while(r < n){
            if(arr[r] > arr[r - 1]){
                mode = r % 2;
            }else if(arr[r] < arr[r - 1]){
                mode = !(r % 2);
            }else{
                ++r, ++l;
                continue;
            }
            
            while(r < n){
                if(mode == 1){
                    if((r % 2 && arr[r] > arr[r - 1]) || ((r % 2) == 0 && arr[r] < arr[r - 1]))
                        ++r;
                    else
                        break;
                }else{
                    if((r % 2 && arr[r] < arr[r - 1]) || ((r % 2) == 0 && arr[r] > arr[r - 1]))
                        ++r;
                    else
                        break;
                }
            }
            
            res = max(res, r - l + 1);
            if(r - l >= 2)
                --r;
            l = r;
            
        }
        return res;
    }
};