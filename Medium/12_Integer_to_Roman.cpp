//
//Runtime 4
//Memory Usage

char m[][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int val[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
class Solution {
	
	
	
public:
    string intToRoman(int num) {
        string result;
        int index = 12;
        while(num > 0) {
            while(val[index] <= num) {
	    	result += m[index];
		num -= val[index];
	    }
	    --index;
        }
	return result;
        
    }
};
