//djs
//Runtime 6
//Memory Usage 11.3
class Solution {
public:
    int djs[26];
    int parent(int u){
        return djs[u] == u ? u : djs[u] = parent(djs[u]);
    }
    bool equationsPossible(vector<string>& equations) {
        vector<pair<char, char>> v;
        for(int i = 0; i < 26; ++i)
            djs[i] = i;
        for(const auto &eq : equations){
            if(eq[1] == '=')
                djs[parent(eq[0] - 'a')] = parent(eq[3] - 'a');
            else
                v.push_back({eq[0] - 'a', eq[3] - 'a'});
        }
        
        for(const auto [a, b] : v){
            if(parent(a) == parent(b))
                return false;
        }
        return true;
    }
};