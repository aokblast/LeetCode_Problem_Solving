//dfs
//Runtime 16
//Memory Usage 13.7
class Solution {
	public:
		    int cnt = 0;
			    unordered_map<string, int> m;
				    int rd[305] = {0};
    vector<string> ans;
    vector<int> adjs[305];
    int visit[305] = {false};
    string vu[305];
    void dfs(int start){
		        while(!adjs[start].empty()){
					            int n = adjs[start][0];
								            adjs[start].erase(adjs[start].begin());
											            dfs(n);
														        }
				        ans.push_back(vu[start]);
						    }
	    vector<string> findItinerary(vector<vector<string>>& tickets) {
			        for(vector<string> &s : tickets){
						            if(m.find(s[0]) == m.end())m[s[0]] = ++cnt, vu[cnt] = s[0];
									            if(m.find(s[1]) == m.end())m[s[1]] = ++cnt, vu[cnt] = s[1];
												            adjs[m[s[0]]].push_back(m[s[1]]);
															        }
					        for(vector<int> &s : adjs){
								            sort(s.begin(), s.end(), [this](int n1, int n2){return vu[n1] < vu[n2];});
							        }
		        dfs(m["JFK"]);
		        reverse(ans.begin(), ans.end());
		        return ans;
		        
		    }
};}
							}
					}
		}
				}
	}}}
}
