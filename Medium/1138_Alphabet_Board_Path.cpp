//greedy
//Runtime 2
//Memory Usage 6.1

class Solution {
public:
    string alphabetBoardPath(string target) {
        int arr[26][2] = {{0}};
        
        for(int i = 0; i < 26; ++i) {
            arr[i][0] = i / 5;
            arr[i][1] = i % 5;
        }
        
        string res;
        int i = 0, j = 0;
        
        for(char c : target) {
            int idx = c - 'a';
            int dx = arr[idx][0] - i, dy = arr[idx][1] - j;
            while(dx < 0) {
                res += 'U';
                ++dx;
            }
            while(dy > 0) {
                res += 'R';
                --dy;
            }
            while(dy < 0) {
                res += 'L';
                ++dy;
            }
            while(dx > 0) {
                res += 'D';
                --dx;
            }
            
            res += '!';
            i = arr[idx][0], j = arr[idx][1];
        }
        return res;
    }
};