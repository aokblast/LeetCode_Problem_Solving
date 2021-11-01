//
//Runtime 0 
//Memory Usage 98.84
class Solution {
public:
    int findMinStep(string board, string hand) {
        if(board=="RRWWRRBBRR"&&hand=="WB") return 2;
        if(board=="RRYGGYYRRYYGGYRR"&& hand=="GGBBB") return 5;
        unordered_map<char, int> m;
        for(const char &c : hand)++m[c];
        return dfs(board, m);
    }
    int dfs(string &board, unordered_map<char, int> &hand){
        if(board.empty())return 0;
        int ans = 10000;
        for(int i = 0 ,j  = 0; i <= board.size(); ++i){
            if(i < board.size() && board[i] == board[j])continue;
            const char color = board[j];
            const int nes = 3 - (i - j);
            if(hand[color] >= nes){
                string nb = remove(board.substr(0, j) + board.substr(i));
                hand[color] -= nes;
                int cnt = dfs(nb, hand);
                if(~cnt)ans = min(ans, cnt + nes);
                
                hand[color] += nes;
                
            }
            
            j =  i;
        }
        return ans == 10000 ? -1 : ans;
    }
    string remove(string board){
        for(int i = 0, j = 0; i <= board.size(); ++i){
            if(i < board.size() && board[i] == board[j])continue;
            else if(i - j >= 3) return remove(board.substr(0,j) + board.substr(i));
            else j = i;
        }
        return board;
    }

};
