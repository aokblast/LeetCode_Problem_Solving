/binary search
//Runtime 0
//Memory 5.9
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0, r = sqrt(c), b = sqrt(c);
        if(r *r == c)return true;
        while(a <= b){
            long val = a * a + b * b;
            if(val > c){
                --b;
            }else if(val < c){
                ++a;
            }else{
                return true;
            }

        }
        return false;
    }
};