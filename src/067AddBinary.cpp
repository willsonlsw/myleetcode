#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution{
public:
	string addBinary(string a, string b){
		if (a.size() > b.size()) 
			return addBinary(b, a);
			
		int n = a.size() - 1, m = b.size() - 1;
		int tmp = 0;
		string str = "";
		for (int i = 0; i <= m; ++i){
			if (i <= n) tmp = (b[m-i] - '0') + (a[n-i] - '0') + tmp;
			else tmp = b[m-i] - '0' + tmp;
			str += '0' + tmp % 2;
			tmp = tmp / 2;
		}
		if (tmp > 0) str += '1';
		reverse(str.begin(), str.end());
		return str;
	}
};

int main(){
	string a, b;
	cin >> a >> b;
	Solution sc;
	cout << sc.addBinary(a, b) << endl;
	return 0;
}