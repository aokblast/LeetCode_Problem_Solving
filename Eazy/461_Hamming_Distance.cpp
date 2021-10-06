//
//Runtime 9 
//Memory Usage 6
class Solution {
public:
    int count(int num){
        int cnt = 0;
        for(;num; num &= (num - 1), ++cnt);
        return cnt;
    }
    int hammingDistance(int x, int y) {
        return count(x ^ y);
    }
};
