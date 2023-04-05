//
//Runtime 0
//Memory Usage 6

class Solution {
public:
    string getHappyString(int n, int k) {
        k -= 1;
        if(3 * (1 << (n - 1)) <= k)
            return "";

        char c[3][2] = {'b', 'c', 'a', 'c', 'a', 'b'};
        string res;

        
        if(k >= (1 << n))
            res += 'c', k -= 1 << n;
        else if(k >= (1 << (n - 1))) 
            res += 'b', k -= 1 << (n - 1);
        else
            res += 'a';

        if(n == 1)
            return res;
        
        int cur = (1 << (n - 2));
        
        while(res.size() < n) {
            res += c[res.back() - 'a'][k >= cur];

            if(k >= cur)
                k-=cur;
            cur >>= 1;
        } 
        return res;

    }
};