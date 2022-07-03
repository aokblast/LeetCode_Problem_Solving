//
//Runtime 78
//Memory Usage 26.5

class Solution {
public:

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string cur;
        vector<vector<string>> res;
        int n = products.size();
        for(const char c : searchWord){
            cur += c;
            auto iter = lower_bound(products.begin(), products.end(), cur);
            vector<string> tmp;
            int sz = 3;
            while(sz-- && iter != products.end()){
                auto ans = mismatch(cur.begin(), cur.end(), iter->begin());
                if(ans.first == cur.end())
                    tmp.push_back(*iter);
                ++iter;
            }
            res.push_back(tmp);
        }
        return res;
        
    }
};