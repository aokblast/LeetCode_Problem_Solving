//
//Runtime 0
//Memory Usage 7.5
class Solution {
public:
    int n, k;
    bool circularArrayLoop(vector<int>& nums) {
        n = nums.size();
        k = 0;
        int visit[n];
        memset(visit, 0, sizeof(visit));
        for(int i = 0; i < n; ++i){
            if(!visit[i] && check(nums, visit, i)) return true;
        }
        return false;
    }
    bool check(vector<int>& a,int vis[] , int s){
        int last, i = s, p = a[s];
        vis[i] = ++k;
        while(1){
            last = i;
            i = getN(a, i);
            if(p * a[i] < 0)return false;
            if(vis[i] < k && vis[i] > 0) return false;
            if(vis[i] == k)return i != last;
            vis[i] = k;
        }
         return false;
        
    }
    int getN(vector<int> &nums, int i){
        return (((i + nums[i] ) % n) + n) % n; 
    }
};
