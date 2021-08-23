//Manarch


class Solution {
public:
   string preProcess(string &s){
        string result = "$";
        for(char &c : s) result += string("#") + c;
        result += "#^";
        return result;
    }
	
	
	
    string longestPalindrome(string s) {
        string red = preProcess(s);
    	int length = red.length();
	    int p[length];
	    int i_reflect = 0, C = 0, R = 0;
	    for(int i = 1; i < length - 1; ++i){
	 	    i_reflect = 2 * C - i;
	        if(R > i) p[i] = min(R - i, p[i_reflect]);
		    else p[i] = 0;
		    while(red[i+1+p[i]] == red[i - 1 - p[i]]) ++p[i];
		    if((i + p[i]) > R) C = i, R = i + p[i];
	
	    }
	    int maxLen = 0, center = 0;
	    for(int i = 1; i < length - 1; ++i){
		    if(p[i] > maxLen) center = i, maxLen = p[i];
	    }
	    int start = (center - maxLen) / 2;
	    return s.substr(start, maxLen);
    }
    
};
