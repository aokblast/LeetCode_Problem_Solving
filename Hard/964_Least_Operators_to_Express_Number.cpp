//dfs
//Runtime 22
//Memory 5.8
class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        if(target < x){
            return min((x - target) * 2, target * 2 - 1);
        }
        int res = 0;
        long sum = x;
        while(sum < target){
            sum *= x;
            ++res;
        }
        
        if(sum == target)
            return res;
        
        int step1 = INT_MAX;
        int step2 = INT_MAX;
        
        if(sum - target < target)
            step1 = leastOpsExpressTarget(x, sum - target);
        
        step2 = leastOpsExpressTarget(x, target - sum / x) - 1;
        
        
        
        return min(step1, step2) + res + 1;
    }
};