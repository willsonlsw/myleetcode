#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	bool cmp(string &s1, string &s2, int k) {
		for (int i = k; i >= 0; --i)
			if (s1[i] != s2[i]) return false;
		return true;
	}
	
	bool getRes(string &s1, int l1, string &s2, int l2, string &s3, vector<vector<char> > &dp) {
		if (l1 == -1) return cmp(s2, s3, l2); 
		if (l2 == -1) return cmp(s1, s3, l1);
		if (dp[l1][l2] != -1) return dp[l1][l2];
		int l3 = l1 + l2 + 1;
		if (s1[l1] == s3[l3] && s2[l2] == s3[l3]) dp[l1][l2] = getRes(s1, l1-1, s2, l2, s3, dp) | getRes(s1, l1, s2, l2-1, s3, dp);
		else if (s1[l1] == s3[l3]) dp[l1][l2] = getRes(s1, l1-1, s2, l2, s3, dp);
		else if (s2[l2] == s3[l3]) dp[l1][l2] = getRes(s1, l1, s2, l2-1, s3, dp);
		else dp[l1][l2] = 0;
		return dp[l1][l2];
	}
	
	bool isInterleave(string s1, string s2, string s3){
		int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
		if (l1 + l2 != l3) return false;
		
		vector<vector<char> > dp(l1, vector<char>(l2, -1));
		return getRes(s1, l1-1, s2, l2-1, s3, dp);
	}
	
	
	/*
	bool isInterleave(string s1, string s2, string s3) {
		int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
		if (l1 + l2 != l3) return false;
	
		vector<vector<bool> > dp(2, vector<bool>(s2, 0));
		for (int i = 0; i < l2; ++i)
			dp[0][i] = (s2[i] == s3[i]);
		
		for (int k = 0; k < l1; ++k)
			for (int j = 0; j < l2; ++j) {
				int i = k % 2;
				if (s3[i+j] == s1[i]) s3
			}
	}
	*/
};

int main(){
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	Solution sc;
	if (sc.isInterleave(s1, s2, s3)) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}