//
//Runtime 7 
//Memory Usage 6.3
class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1)return 9;
        long long int i = pow(10, n);
        for(long long int x = 1; x < i; ++x){
            long long int a = i - x;
            string str = to_string(a);
           
            long long b = stol(string(str.rbegin(), str.rend()));
            long long int temp =x*x -4*b;
            if(temp>=0)
            {
                long long int temp1 =(int)sqrt(temp);
                if(temp1*temp1 == temp&&(x+temp1)%2==0)
                {
                    long long int ret= i*a;
                    ret = ret+ b;
                    
                    return ret % 1337;
                }
            }
        }
        return 0;
   }
};
