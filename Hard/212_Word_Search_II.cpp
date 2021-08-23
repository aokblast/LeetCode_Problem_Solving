//trie + dfs
//Runtime 240
//Memory Usage 9.4 
static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();
struct Trie{
    int trie[5000][26] = {{0}};
    int top = 0;
    int val[5000] = {0};
    void insert(string &s){
        int size = s.size();
        int f = 0;
        for(int i = 0; i < size; ++i){
            if(!trie[f][s[i] - 'a']) trie[f][s[i] - 'a'] = ++top;
            f = trie[f][s[i] - 'a'];
        }
        ++val[f];
    }
};

class Solution {
public:
    Trie t;
    int m, n;
    bool visit[13][13] = {{0}};
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        string tmp;
        for(auto &w : words) t.insert(w);
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(t.trie[0][board[i][j] - 'a'])  dfs(board, i, j, t.trie[0][board[i][j] - 'a'], tmp);
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& board, int x, int y, int ne, string &s){
        s.push_back(board[x][y]);
        visit[x][y] = true;
        if(t.val[ne]){
            ans.push_back(s);
            --t.val[ne];
        }
        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || visit[nx][ny] || !t.trie[ne][board[nx][ny] - 'a']) continue;
            dfs(board, nx, ny, t.trie[ne][board[nx][ny] - 'a'], s);
        }
        
        
        visit[x][y] = false;
        s.pop_back();
    }
};
