//dfs
//Runtime 0
//Memory Usage 6.4

char ma[][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
	vector<string> result;
	string ans;
	void dfs(const char *p){
		if(*p == '\0'){
			result.push_back(ans);
			return;
		}
		for(char *ptr = ma[*p - '2']; *ptr != '\0'; ++ptr){
			ans.push_back(*ptr);
			dfs(p + 1);
			ans.pop_back();
		}	
	}
	
	
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
 		dfs(digits.c_str());
	   	return result;	
    }
};
