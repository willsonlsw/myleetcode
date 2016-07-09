#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int sl = s.size(), tl = t.size();
		vector<vector<int> > dp(sl + 1, vector<int>(tl + 1, 0));
		
		for (int i = 0; i <= sl; ++i) dp[i][0] = 1;
		for (int i = 1; i <= sl; ++i)
			for (int j = 1; j <= tl; ++j) {
				dp[i][j] = dp[i-1][j];
				if (s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1]; 
			}
		return dp[sl][tl];
	}
	
	/*
	void dfs(string &s, string &t, int sidx, int tidx, int &count){
		if (tidx == t.size()) {
			count++;
			return;
		}
		int eidx = s.size() - (t.size() - tidx) + 1;
		if (eidx > s.size()) return;
		for (int i = sidx; i < eidx; ++i)
			if (s[i] == t[tidx]) dfs(s, t, i+1, tidx+1, count);
	}
	
	int numDistinct(string s, string t) {
 		int sl = s.size(), tl = t.size();
 		if (sl < tl) return 0;
		int count = 0;
 		for (int i = 0; i < sl - tl + 1; ++i)
 			if (s[i] == t[0]) dfs(s, t, i+1, 1, count); 
 		return count;
	}
	*/
};


int main(){
	string s, t;
	cin >> s >> t;
	Solution sc;
	cout << sc.numDistinct(s, t) << endl;
	return 0;
}