//
//Runtime 0 
//Memory Usage 6
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while(columnNumber){
            columnNumber -= 1;
            result += 'A' +((columnNumber % 26)  + 26) % 26;
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
