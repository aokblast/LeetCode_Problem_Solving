class Solution {
public:
    vector<int> diStringMatch(string s) {
        int min = 0, max = s.length();
        vector <int> result;
        for (auto &c : s){
            if (c == 'D'){
                result.push_back(max--);
            }
            else result.push_back(min++);
        }
        result.push_back(max);
        return result;
    }
};
