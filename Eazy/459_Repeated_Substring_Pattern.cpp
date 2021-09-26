//kmp
//Runtime 16
//Memory Usage 12.7
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int m = s.size();
        vector<int> f(m + 1, 0);
        int i = 0, j = -1;
        f[0] = -1;
        while(i < m){
		    if(j == -1 || s[i] == s[j]){
			    f[++i] = ++j;
		    }else{
			    j = f[j];
		    }
        }
        return f[m] && (f[m] % (m - f[m]) == 0);
    }
};
