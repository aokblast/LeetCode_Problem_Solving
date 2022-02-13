//dfs
//Runtime 0
//Memory Usage 6.6
class Solution {
public:
    map<string, int> mp;
    void dfs(string &formula, int start, int end, int time){
        int cnt = 0;
        string ele;
        for(int i = start; i <= end; ++i){
            
            char c = formula[i];
            if(c == '('){
                int left = i + 1;
                int layer = 0;
                ++i;
                while(i <= end && (formula[i] != ')' || layer))
                    layer += formula[i] == '(' ? 1 : formula[i] == ')' ? -1 : 0, ++i;
                int right = i - 1;
                ++i;
                int cnt = 0;
                if(isdigit(formula[i])){
                    while(i <= end && isdigit(formula[i])){
                        cnt = cnt * 10 - '0' + formula[i];
                        ++i;
                    }
                    dfs(formula, left, right, time * cnt);
                }else{
                    dfs(formula, left, right, time);
                }
                --i;
            }else{
                ele.clear();
                ele += formula[i];
                ++i;
                while(islower(formula[i])){
                    ele += formula[i];
                    ++i;
                }
                int cnt = 0;
                if(isdigit(formula[i])){
                    while(i <= end && isdigit(formula[i])){
                        cnt = cnt * 10 - '0' + formula[i];
                        ++i;
                    }
                    mp[ele] += time * cnt;
                }else{
                    mp[ele] += time;
                    
                }
                --i;
            }
            
        }
    }
    string countOfAtoms(string formula) {
        dfs(formula, 0, formula.size() - 1, 1);
        string res;
        for(const auto &[ele, time] : mp){
            res += ele + (time == 1 ? "" : to_string(time));
        }
        return res;
    }
};