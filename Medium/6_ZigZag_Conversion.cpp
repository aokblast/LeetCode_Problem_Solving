class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string result;
        int length = s.length();
        int period = 2 * numRows - 2, next = 0;;
        for(int i = 0; i < numRows; ++i){
            for(int j = i;  j < length; j += period ){
                result += s[j];
                next = j + period - 2 * i;
                if(i != 0 && i != numRows - 1 && next < length) result += s[next];
                
            }
            
        }
        return result;
    }
};
