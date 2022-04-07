//suffix sum
//Runtime 68
//Memory Usage 68.1
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        long long cur = 0;
        int n = shifts.size();
        
        for(int i = n - 1; i >= 0; --i){
            cur += shifts[i];
            s[i] = (s[i] - 'a' + cur) % 26 + 'a';
        }
        return s;
        
    }
};