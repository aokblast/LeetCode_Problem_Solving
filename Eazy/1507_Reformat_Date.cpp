//
//Runtime 0
//Memory Usage 6
class Solution {
public:
    string reformatDate(string date) {
        stringstream ss(date);

        static unordered_map<string, string> mp 
        = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}
        , {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}
        , {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}
        , {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};

        string day, month, year;
        ss >> day >> month >> year;

        day = isdigit(day[1]) ? string() + day[0] + day[1] : string() + '0' + day[0];

        return year + '-' + mp[month] + '-' +  day;
    }
};