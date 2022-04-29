//
//Runtime 1
//Memory Usage 40.9

class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
    	int[] startPoints = new int[26];
    	
    	
    	Arrays.fill(startPoints, -1);
    	List<String> res = new ArrayList<>();
    	for(int i = 0; i < pattern.length(); ++i) {
    		char c = pattern.charAt(i);
    		if(startPoints[c - 'a'] == -1)
    			startPoints[c - 'a'] = i;
    	}
    	
    	for(String word : words) {
    		int[] mp = new int[26];
    		Arrays.fill(mp, -1);
    		for(int i = 0; i < 26; ++i)
    			if(startPoints[i] != -1) {
    				char c = word.charAt(startPoints[i]);
    				mp[c - 'a'] = i;
    			}
    		boolean ans = true;
    		for(int i = 0; i < word.length(); ++i) {
    			char c = word.charAt(i);
    			if(mp[c - 'a'] == -1) {
    				ans = false;
    				break;
    			}
    			if((char)('a' + mp[c - 'a']) != pattern.charAt(i)){
                    ans = false;
                    break;
                }
    			
    		}
    		if(ans)
    			res.add(word);
    	}
    	return res;
    	
    	
    }
}