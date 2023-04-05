//
//Runtime 0
//Memory Usage 6.1

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i <= n / 2; ++i) {
            string a = to_string(i), b = to_string(n - i);
            auto check = [&](const string &str) {
                return find_if(str.begin(), str.end(), [](const auto c) {return c == '0';}) == str.end();
            };
            if(check(a) && check(b))
                return {i, n - i};
        }
        return {-1};
    }
};