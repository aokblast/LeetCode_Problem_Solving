//
//Runtime 0
//Memory Usage 5.8

class Solution {
public:
    int maximumSwap(int num) {
        string res = to_string(num);
        int l = 0, exc, n = res.size(), r = n - 1;
        while(l < n - 1){
            exc = r = n - 1;
            while(r >= l){
                if(res[exc] < res[r])
                    exc = r; 
                --r;
            }

            if(res[exc] > res[l]){
                swap(res[exc], res[l]);
                break;
            }   
            ++l;
            
        }
        return stoi(res);
    }
};