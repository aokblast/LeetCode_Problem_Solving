//
//Runtime 113
//Memory Usage 68.4

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), mx = arr[n - 1];
        arr[n - 1] = -1;
        
        for(int i = n - 2;  i >= 0; --i) {
            int pre = arr[i];
            arr[i] = mx;
            mx = max(mx, pre);
        }

        return arr;
    }
};