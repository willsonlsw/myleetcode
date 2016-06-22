#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	bool valid(string s, int i, int j) {
		int tmp = 0; 
		for (int k = i; k < j; ++k) {
			tmp = tmp * 10 + s[k] - '0';
			if (tmp > 255) return false;
		}
		if (tmp == 0 && i + 1 < j && s[i] == '0') return false; 
		if (tmp > 0 && s[i] == '0') return false;
		if (0 <= tmp && tmp <= 255) return true;
		return false;
	}
	
	vector<string> restoreIpAddresses(string s){
		vector<string> res;
		for (int i = 1; i < s.size() - 2; ++i) {
			if (!valid(s, 0, i)) continue;
			for (int j = i + 1; j < s.size() - 1; ++j) {
				if (!valid(s, i, j)) continue;
				for (int k = j + 1; k < s.size(); ++k) {
					if (!valid(s, j, k)) continue;
					if (!valid(s, k, s.size())) continue;
					string str = s.substr(0, i) + '.' + s.substr(i, j - i) + '.' + s.substr(j, k - j) + '.' + s.substr(k, s.size() - k);
					res.push_back(str);
				}
			}
		}
		return res;
	}
};

int main(){
	string str;
	cin >> str;
	Solution sc;
	vector<string> res = sc.restoreIpAddresses(str);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	return 0;
}