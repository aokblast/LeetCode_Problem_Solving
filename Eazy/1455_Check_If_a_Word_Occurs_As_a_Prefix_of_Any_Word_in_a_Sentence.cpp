//
//Runtime 0
//Memory Usage 6.2

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);

        string cur;
        int i = 0;
        while(ss >> cur) {
            ++i;
            if(cur.substr(0, searchWord.size()) == searchWord)
                return i;
        }

        return -1;
    }
};