//dfs + memo + binary
//Runtime 51
//Memory Usage 42.9


class Solution {
	int[][] dp;
	
	int dfs(int k, int n) {
		if(n == 0 || n == 1 || k == 1)
			return n;
		if(dp[k][n] > 0)
			return dp[k][n];
		
		int res = Integer.MAX_VALUE;
		
		int l = 1, r = n;
		
		while(l < r) {
			int mid = l + (r - l) / 2;
			int up = dfs(k, n - mid), down = dfs(k - 1, mid - 1);
			int tmp = Math.max(up, down) + 1;
			if(up < down) {
				r = mid;
			}else {
				l = mid + 1;
			}
			res = Math.min(res, tmp);
		}
		dp[k][n] = res;
		return res;
		
		
	}
	
    public int superEggDrop(int k, int n) {
    	dp = new int[k + 1][n + 1];
    	return dfs(k, n);
    }
}

//revese dp
//Runtime 0
//Memory Usage 39.2

class Solution {
    public int superEggDrop(int k, int n) {
    	int[] dp = new int[k + 1];
    	
    	int step = 0;
    	while(dp[k] < n) {
    		++step;
    		for(int i = k; i >= 1; --i)
    			dp[i] += dp[i - 1] + 1;
    	}
    	return step;
    	
    }
}