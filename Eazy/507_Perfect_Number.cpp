//
//Runtime 0 
//Memory Usage 5.9
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1)return false;
        int sum = 1;
        int sq = sqrt(num);
        for(int i  = 2; i <= sq; ++i){
            sum += ((num % i) == 0 ? (num / i == i ? i : (i + num / i)) : 0);
        }
        return sum == num;
    }
};
