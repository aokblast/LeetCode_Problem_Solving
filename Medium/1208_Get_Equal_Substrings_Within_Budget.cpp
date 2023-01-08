//Sliding Window
//Runtime 0
//Memory Usage 7.7 

class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int n = s.length(), i = 0, j;
        for (j = 0; j < n; ++j) {
            if ((k -= abs(s[j] - t[j])) < 0) 
                if(k < 0)
                    k += abs(s[i] - t[i++]);
            
        }

        return j - i;
    }
};