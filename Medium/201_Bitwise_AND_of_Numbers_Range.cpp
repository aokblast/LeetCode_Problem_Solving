//
//Runtime 8
//Memory Usage 6
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return right << shift;
    }
};
