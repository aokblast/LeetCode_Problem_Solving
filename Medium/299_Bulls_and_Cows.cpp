//
//Runtime 4
//Memory Usage 6.4
class Solution {
public:
    int m1[10] = {0}, m2[10] = {0};
    string getHint(string secret, string guess) {
        int n = secret.length();
        int a = 0, b= 0;
        for(int i = 0; i < n; ++i){
            a += (secret[i] == guess[i]);
            ++m1[secret[i] - '0'], ++m2[guess[i] - '0'];
        }
        for(int i = 0; i < 10; ++i){
            b += min(m1[i], m2[i]);
        }
        return to_string(a) + 'A' + to_string(b - a) + 'B';
    }
};
