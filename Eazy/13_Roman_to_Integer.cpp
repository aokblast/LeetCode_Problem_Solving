//
//Runtime 8
//Memory Usage 6.1
inline int getVal (char c){
    switch(c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}

class Solution {
    
    
public:
    int romanToInt(string s) {
    int result = 0;

	int len = s.length();
	for(int i = 0; i < len - 1; ++i){
		if(getVal(s[i]) < getVal(s[i + 1])){
			result -= getVal(s[i]);		
		}else{
			result += getVal(s[i]);
		}	
	}
    result += getVal(s[len - 1]);
	return result;
        
    }
};
