//Greedy
//Runtime 2
//Memory Usage 7.3

class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        int l = 0, r = n - 1, res = 0;
        string a, b;
        while(l < r) {
            a += text[l++];
            b += text[r--];
            string rev = b;
            reverse(rev.begin(), rev.end());
            if(a == rev) {
                ++res;
                a = "";
                b = "";
            }
        }
        res *= 2;
        if(a.size() || n % 2)
            ++res;
        return res;
    }
};