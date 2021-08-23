//
//Runtime 0
//Memory Usage 9.2

int lens[200];


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		int total = strs.size(), index = 0;
        string result;
		char c;
		for(int i = 0; i < total; ++i) lens[i] = strs[i].length();
		while(1){
			if(index >= lens[0])goto ret;
			c = strs[0][index];
			for(int i = 1; i < total; ++i) if(index >= lens[i] || strs[i][index] != c) goto ret;	
			result += c;
			++index;
		}
	ret:
		return result;
	}
};
