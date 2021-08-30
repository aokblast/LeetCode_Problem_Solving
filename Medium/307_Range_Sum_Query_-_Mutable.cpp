//Ferwick Tree
//Runtime 507
//Memory Usage 151.6
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

class NumArray {
public:
    int arr[30005] = {0}, block[6000] = {0};
    int size = 0;
    NumArray(vector<int>& nums) {
        if(!nums.size()) return;
        double root = sqrt(nums.size());
        size = ceil(nums.size() / root);
        for(int i = 0; i < nums.size(); ++i){
            arr[i] = nums[i];
            block[i / size] += nums[i];
        }
    }
    
    void update(int index, int val) {
        int idx = index / size;
        block[idx] += (val - arr[index]);
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        int result = 0 ;
        int start = left / size;
        int end = right / size;
        if(start == end){
            for(int i = left; i <= right; ++i){
                result += arr[i];
            }
            return result;
        }
        for(int i = left; i < size * (start + 1); ++i){
            result += arr[i];
        }
        for(int i = start + 1; i < end; ++i){
            result += block[i];
        }
        for(int i = (end) * size; i <= right; ++i){
            result += arr[i];
        }
        return result;
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
