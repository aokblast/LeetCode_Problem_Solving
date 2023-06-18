//Greedy
//Runtime 120
//Memory 73.1
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0], n = target.size();

        for(int i = 1; i < n; ++i) {
            res += max(0, target[i] - target[i - 1]);
        }
        
        return res;
    }
};