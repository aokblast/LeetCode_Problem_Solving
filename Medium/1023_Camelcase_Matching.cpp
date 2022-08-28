//Greedy 
//Runtime 0
//Memory Usage 7.1

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        
        for(const auto &q : queries) {
            int i = 0, j = 0;
            bool hasAns = true;
            for(; i < q.size(); ++i){
                if(q[i] == pattern[j]){
                    if(++j == pattern.size()){
                        ++i;
                        break;
                    }
                }
                else if(isupper(q[i])){
                    hasAns = false;
                    break;
                }
            }
            
            
            if(j != pattern.size())
                hasAns = false;
            
            if(hasAns){
                while(i < q.size()){
                    if(isupper(q[i])){
                        hasAns = false;
                        break;
                    }
                    ++i;
                }
            }
            res.push_back(hasAns);
        }
        return res;
    }
};
