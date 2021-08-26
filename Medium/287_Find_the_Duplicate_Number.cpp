//
//Runtime 96
//Memory Usage 61.5
class Solution {
public:
    int count[100005];
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = 0;
        for(int &num : nums){
            count[num]++;
            if(count[num] > 1) return num;
        }
        return 0;
    }
};
//Binary Search
//Runtime 116
//Memory Usage 61.3
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (right + left) / 2 ,cnt = 0;
            for(auto &num : nums) if(num <= mid)  ++cnt;
            if(cnt <= mid) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};//Pointer
//Runtime 40
//Memory Usage 61
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int slow = 0, fast = 0, tag = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        while(true){
            slow = nums[slow], tag = nums[tag];
            if(slow == tag) break;
        }
        return slow;
        
    }
};
