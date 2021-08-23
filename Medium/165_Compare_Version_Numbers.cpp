//
//Runtime 0
//Memory Usage 6.3

class Solution {

public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1 + "."), s2(version2 + ".");
        int num1 = 0, num2 = 0;
        char c;
        while(s1.good() || s2.good()){
            if(s1.good())s1 >> num1 >> c;
            if(s2.good())s2 >> num2 >> c;
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            num1 = num2 = 0;
        }

       return 0;
    }
};
