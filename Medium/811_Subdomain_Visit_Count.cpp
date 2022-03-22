//
//Runtime 20
//Memory Usage 11.5

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;

        for(const auto &domain : cpdomains){
            auto pos = domain.find(' ');
            int cnt = stoi(domain.substr(0, pos + 1));
            for(int i = domain.size() - 1; i >= pos; --i)
                if(domain[i] == '.' || i == pos)
                    mp[domain.substr(i + 1)] += cnt;
                
        }
        vector<string> res;
        for(const auto &[str, cnt] : mp)
            res.emplace_back(to_string(cnt) + ' ' + str);
        return res;
    }
};