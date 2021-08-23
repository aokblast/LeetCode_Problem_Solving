//
//Runtim 0
//Memory Usage 5.8
class Solution {
public:
    int addDigits(int num) {
        int tmp = 0;
        while(num >= 10){
            tmp = 0;
            while(num > 0){
                tmp += num % 10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};
