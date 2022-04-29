//
//Runtime 17
//Memory Usage 72.7

class Solution {
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {

    	int n = aliceSizes.length, m = bobSizes.length;
    	
    	int s1 = 0, s2 = 0;
    	Set<Integer> s = new HashSet<>();
    	
    	for(int candy : aliceSizes) {
    		s1 += candy; 
            s.add(candy);
    	}
    	for(int candy : bobSizes)
    		s2 += candy;
    	int avg = (s1 + s2) / 2;
    	s1 = avg - s1;
    	
    	for(int candy : bobSizes)
    		if(s.contains(candy - s1))
    			return new int[] {candy - s1, candy};
    		
    	return null;
    	
    	
    	
    }

}