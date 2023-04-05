//
//Runtime 0
//Memory Usage 6

class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num), b = a;

        int n = a.size(), i = 0;

        char rep, exc;

        if(a.front() != '1') {
            rep = a[0];
            exc = '1';
        } else {
            for(i = 1; i < n; ++i)
                if(a[i] > '1')
                    break;
            rep = a[i];
            
            exc = (a.front() == rep) ? '1' : '0';
        }

        for(char &c : a)
            if(rep == c)
                c = exc;
        
        for(i = 0; i < n; ++i)
            if(b[i] != '9')
                break;

        rep = b[i];

        for(char &c : b)
            if(rep == c)
                c = '9';

        return stol(b) - stol(a);
    }
};