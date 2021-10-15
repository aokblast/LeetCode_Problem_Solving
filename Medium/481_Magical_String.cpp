//
//Runtime 7 
//Memory Usage 7.7
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        char c = '2';
        int ans = 1;
        while(s.size() < n){
            s += string(s[i] - '0', c == '2' ? ans += ((s.size() + s[i] - '0') > n ? n - s.size() : s[i] - '0'), c = '1': c = '2');
            ++i;
        }
        return ans;
    }
};
