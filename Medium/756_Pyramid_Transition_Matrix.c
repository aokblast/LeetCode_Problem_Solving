//dfs
//Runtime 0
//Memory Usage 8

class Solution {
public:
    unordered_map<int, vector<char>> m;
    unordered_map<string, bool> vis;
    bool dfs(string buttom, string up){
        if(buttom.size() ==  2 && up.size() == 1)
            return true;
        if(vis.find(buttom) != vis.end())
            return false;
        if(up.size() + 1 == buttom.size())
            return dfs(up, "");
        int cur = buttom[up.size() + 1] << 8 | buttom[up.size()];
        if(m.find(cur) != m.end()){
            up.push_back('0');
            for(const char c : m[cur]){
                up.back() = c;
                if(dfs(buttom, up))
                    return true;
            }
            return vis[buttom] = false;
        }
        else
            return vis[buttom] = false;

    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(const auto &allow : allowed)
            m[(allow[1] << 8) | allow[0]].push_back(allow[2]);
        
        
        return dfs(bottom, "");
        
    }
};