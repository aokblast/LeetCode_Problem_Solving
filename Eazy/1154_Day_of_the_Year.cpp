//
//Runtime 15
//Memory 5.9

class Solution {
public:
    constexpr static int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear(string date) {
        int res = 0;
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        
        for(int i = 1; i < month; ++i)
            res += days[i];
        res += day;
        if(month >= 3) {
           res += (year%4) == 0 && (year%100) != 0 || (year%400) == 0; 
        }
        return res;
    }
};