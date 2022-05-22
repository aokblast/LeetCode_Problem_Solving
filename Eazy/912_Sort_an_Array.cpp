//
//Runtime 94
//Memory Usage 28.7
class Solution {
public:
    int tmp[50005];
    void mergeSort(vector<int> &v, int l, int r){
        if(l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);
        int a = l, b = mid + 1, idx = 0;
        while(a <= mid && b <= r)
            tmp[idx++] = v[a] < v[b] ? v[a++] : v[b++];
        while(a <= mid)
            tmp[idx++] = v[a++];
        while(b <= r)
            tmp[idx++] = v[b++];
        idx = 0;

        for(int i = l; i <= r; ++i)
            v[i] = tmp[idx++];
        
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};