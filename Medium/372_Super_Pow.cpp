//Fast Power
//Runtime 4
//Memory Usage 11.5
class Solution {
public:
    int superPow(int a, vector<int>& b) {

        int ans = 1;
        for(int &n : b){
            ans = pow(ans, 10) * pow(a, n) % 1337; 
        }
        return ans;
    }
    int pow(int a, int b){
        int ans = 1;
        a %= 1337;
        while(b){
            if(b & 1) ans = (ans * a) % 1337;
            a = (a * a) % 1337;
            b >>= 1;
        }
        return ans;
    }
};
