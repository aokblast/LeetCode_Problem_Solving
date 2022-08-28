//Greedy
//Runtime 3
//Memory Usage 6.2

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a > b)
            swap(a, b);
        if(b > c)
            swap(b, c);
        if(b < a)
            swap(a, b);
        
        int mn = 0;
        
        if(b - a == 1 && c - b == 1)
            mn = 0;
        else if (b - a == 1 || c - b == 1 || c - b == 2 || b - a == 2)
            mn = 1;
        else
            mn = 2;
        
        return {mn, b - a - 1 + c - b - 1};
    }
};
