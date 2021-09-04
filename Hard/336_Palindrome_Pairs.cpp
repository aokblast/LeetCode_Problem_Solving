//hash_map
//Runtime 232
//Memory Usage 104.9
class Solution {
	public:
		    vector<vector<int>> ans;
			    unordered_map<string, int> m;
				    set<int> len;
					    vector<vector<int>> palindromePairs(vector<string>& words) {
							        int n = words.size();
									        for(int i = 0; i < n; ++i){
												            m[words[i]] = i;
															            len.insert( words[i].size());
																		        }
											        for(int i = 0; i < n; ++i){
														            string t = words[i];
																	            int s = t.size();
																				            reverse(t.begin(), t.end());
																							            if(m.count(t) && m[t] != i){
																											                ans.push_back({i, m[t]});
																										            }
													            set<int>::iterator ed = len.find(s);
													            for(set<int>::iterator st = len.begin(); st != ed; ++st){
																	                int sz = *st;
																					                if(valid(t, 0, s - sz - 1)){
																										                    string t2 = t.substr(s - sz);
																															                    if(m.count(t2)) ans.push_back({i, m[t2]});
																									                }
																                if(valid(t, sz, s - 1)){
																					                    string t2 = t.substr(0, sz);
																										                    if(m.count(t2)) ans.push_back({m[t2], i});
																				                }
																            }
													            
													        }
						        return ans;
						    }
    bool valid(string &s, int left, int right){
		        while(left < right){
					            if(s[left++] != s[right--])return false;
								        }
				        return true;
						    }
};
				}
	}}
																				}}
																									}
																}}
																										}
													}
											}
						}
}
