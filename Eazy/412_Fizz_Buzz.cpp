//
//Runtime 3
//Memory Usage 7.9
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; ++i){
            ans.push_back((!(i % 3) && !(i % 5)) ? "FizzBuzz" : !(i % 3) ? "Fizz" : !(i % 5) ? "Buzz" : to_string(i));
        }
        return ans;
    }
};
