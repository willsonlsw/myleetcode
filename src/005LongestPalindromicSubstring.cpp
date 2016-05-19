class Solution005 {
public:
	string longestPalindrome(string s) {
		int slen = s.size();
		int f[1001][1001];
		memset(f, 0, sizeof(f));

		int maxlen = 0, tmpi, tmpj;

		int j;
		for (int k = 0; k < slen; ++k)
			for (int i = k; i < slen; ++i) {
				j = i - k;
				if (i == j) f[i][j] = 1;
				else if (i == j + 1) {
					if (s[i] == s[j]) f[i][j] = 1;
					else f[i][j] = 0;
				}
				else {
					if (f[i - 1][j + 1] && s[i] == s[j]) f[i][j] = 1;
					else f[i][j] = 0;
				}

				if (f[i][j] == 1 && k > maxlen) {
					tmpi = i;
					tmpj = j;
					maxlen = k;
				}
			}
		string strtmp = s.substr(tmpj, maxlen + 1);
		return strtmp;
	}
};