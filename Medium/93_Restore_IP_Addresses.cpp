//dfs
//Runtime 0
//Memory Usage 6.5

class Solution {
public:
    vector<string> result;
    int size;
    void dfs(string &s, string &cur,int index, int element){
        if( size == index && element == 4){
            
            result.push_back(cur.substr(0, cur.size() - 1));
            return;
        }
        if(element == 4){
            return ;
        }
        if(s[index] == '0'){
            cur+="0.";
            dfs(s, cur, index+1, element + 1);
            cur.pop_back();
            cur.pop_back();

        }
        else{
            int num = 0;
            string ipSeg;
            for(int i = 0; i < 4 && index + i < size; ++i){
                num = num * 10 + s[index + i] - '0';
                if(num > 255){
                    break;
                }
                ipSeg.push_back(s[index + i]);
                cur+= ipSeg + '.';
                
                dfs(s, cur, index + i + 1, element + 1);
                for(int j = 0; j <= i  + 1; ++j){
                    cur.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        size = s.size();
        string tmp;
        dfs(s, tmp, 0, 0);
        return result;
    }
};
