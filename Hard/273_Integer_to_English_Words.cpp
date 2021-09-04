//
//Runtime 0
//Memory Usage 7
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> v = {"Thousand", "Million", "Billion"};
    string hundredC(int num){
        int a = num / 100, b = num % 100, c = num % 10;
        string result = b < 20 ? v1[b] : v2[b / 10] + (c ? " " + v1[c] : "");
        if(a) result = v1[a] + " Hundred" + (b ? " " + result : "");
        return result;
    }
    
    
    string numberToWords(int num) {
        string ans = hundredC(num % 1000);
        for(int i = 0; i < 3; ++i){
            num /= 1000;
            if(num % 1000) ans  =  hundredC(num % 1000) + " " + v[i] + " " + ans;
        }
        while(ans.back() == ' ') ans.pop_back();
        return ans.empty() ? "Zero" : ans; 
    }
};
