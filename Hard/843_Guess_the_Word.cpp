//
//Runtime 0
//Memory Usage 6.4

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int cnt = 10;
        srand(time(NULL));
        while(cnt--){
            const auto choose = wordlist[rand() % wordlist.size()];
            const auto mat = master.guess(choose);
            if(mat == 6)
                break;
            wordlist.erase(remove_if(wordlist.begin(), wordlist.end(), 
                [&](const auto &word){
                int cur = 0;
                for(int i = 0; i < 6; ++i)
                    cur += choose[i] == word[i];
                return cur != mat;
            }), wordlist.end());
        }
    }
};