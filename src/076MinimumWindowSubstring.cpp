#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution{
public:
	string minWindow(string s, string t) {
		vector<int> m(129, 0);
		for (auto ch : t) m[int(ch)]++;
		int count = t.size(), start = 0, end = 0, minlen = 0x7fffffff, minstart, minend;
		while (end < s.size()){
			if (m[int(s[end])] > 0) count--;
			m[int(s[end])]--;
			end++;
			while (count == 0){
				if (end - start < minlen) {
					minlen = end - start;
					minstart = start;
					minend = end;
				}
				m[int(s[start])]++;
				if (m[int(s[start])] > 0) count++;
				start++;
			}
		}
		
		if (minlen != 0x7fffffff) return s.substr(minstart, minlen);
		else return "";
	}
};

int main(){
	string s, t;
	cin >> s >> t;
	Solution sc;
	cout << sc.minWindow(s, t) << endl;
	return 0;
}