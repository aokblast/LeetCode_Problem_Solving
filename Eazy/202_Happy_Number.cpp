//set
//Runtime 0
//Memory Usage 6.4
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        int tmp = 0;
        while(n != 1){
            if(vis.find(n) == vis.end()){
                vis.insert(n);
                while(n){
                    tmp += (n % 10) * (n % 10);
                    n /= 10;
                }
                
                 n = tmp;
                tmp = 0;
            }else{
                return false;
            }
        }
        return true;
    }
};
