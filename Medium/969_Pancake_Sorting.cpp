//Greedy
//Runtime 0
//Memory Usage 11.1


class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        
        int n = arr.size(), r = n - 1;
        
        while(r > 0){
            if(arr[r] == r + 1)
                --r;
            else{
                int l = r - 1;
                while(arr[l] != r + 1)
                    --l;
                reverse(arr.begin(), arr.begin() + l + 1);
                res.push_back(l + 1);
                reverse(arr.begin(), arr.begin() + r + 1);
                res.push_back(r + 1);
                
            }
        }
        return res;        
        
    }
};