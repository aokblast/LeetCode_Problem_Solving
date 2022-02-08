//
//Runtime 24
//Memory Usage 22.5
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int idx = 0, n = arr.size();
        while(idx < n - 1){
            if(arr[idx] < arr[idx + 1])++idx;
            else if(arr[idx] > arr[idx + 1])break;
            else return false;
        }
        if(idx == 0 || idx == n - 1)return false;
        while(idx < n - 1){
            if(arr[idx] > arr[idx + 1])++idx;
            else if(arr[idx] > arr[idx + 1])break;
            else return false;
        }
        return true;
        
    }
};