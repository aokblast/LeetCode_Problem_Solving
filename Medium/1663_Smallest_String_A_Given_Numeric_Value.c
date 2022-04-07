//Greedy
//Runtime 28
//Memory Usage 26.6

public:
    string getSmallestString(int n, int k) {
        int b = ceil((k - n) / 25.0);
        int a = n - b;
        char c = (a + 26 * b) > k  ? (k - a - 26 * (--b)) + '`'  : 0;

        
        return c == 0 ? string(a, 'a') + string(b, 'z') :  string(a, 'a') +  c + string(b, 'z');
        
    }
};