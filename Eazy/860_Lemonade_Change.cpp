//
//Runtime 84
//Memory Usage 83.3

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cur = 0, f = 0, t = 0;
        for(const int bill : bills){
            
            if(bill == 5){
                f += 1;
            }else if(bill == 10 && f != 0){
                f -= 1;
                t += 1;
            }else if(t != 0 && f != 0){
                --f;
                --t;
            }else if(f >= 3){
                f -= 3;
            }else{
                return false;
            }
            
        }
        return true;
    }
};