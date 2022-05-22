//
//Runtime 10
//Memory Usage 10.8

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> ps;
        for(const char c : s){
            if(ps.size() && ps.back().first == c){
                if(++ps.back().second == k)
                    ps.pop_back();
            }else{
                ps.push_back({c, 1});
            }
        }
        string res;
        for(auto [c, cnt] : ps){
            while(cnt--)
                res += c;
        }
        return res;
    }
};