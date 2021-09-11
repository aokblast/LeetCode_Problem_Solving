//dfs
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    int lastRemaining(int n) {
        return dfs(n, true);
    }
    int dfs(int n, bool left){
        if(n <= 1) return 1;
        if(!left &&  !(n %2)) return dfs(n / 2, !left) * 2 - 1;
        return dfs(n / 2, !left) * 2;
    }
};
