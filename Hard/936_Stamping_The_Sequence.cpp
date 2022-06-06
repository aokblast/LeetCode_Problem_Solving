//Greedy
//Runtime 3
//Memory 7.2
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int n = stamp.size(), m = target.size();
        bool match = false;
        do{
            match = false;
            for(int i = m - n; i >=0; --i){
                bool ok = true;
                int cnt = 0;
                for(int j = 0; j < n; ++j){
                    if(target[i + j] == '.')
                        ++cnt;
                    if(target[i + j] != stamp[j] && target[i + j] != '.'){
                        ok = false;
                        break;
                    }
                }
                if(ok && cnt < n){
                    match = true;
                    for(int j = 0; j < n; ++j)
                        target[i + j] = '.';
                    ans.push_back(i);
                }
            }
        }while(match);
        for(int i = 0; i < m; ++i)
            if(target[i] != '.')
                return {};
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};