//
//Runtime 0
//Memory Usage 5.9
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int a = 0, b = 1, c = 1;
    
        for(int i = 3; i <= n; ++i) {
            int tmp = a + b + c;
            a = b, b = c, c = tmp;
        }
        
        return c;
    }
};