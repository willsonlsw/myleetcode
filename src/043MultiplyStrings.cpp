#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	string multiply(string num1, string num2){
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int l1 = num1.length(), l2 = num2.length();
		vector<int> num(l1 + l2, 0);
		
		int idx;
		for (int i = 0; i < l1; ++i)
			for (int j = 0; j < l2; ++j){
				idx = i + j;
				num[idx] += (num1[i] - '0') * (num2[j] - '0');
				num[idx + 1] += num[idx] / 10;
				num[idx] = num[idx] % 10; 
			}
		
		idx = l1 + l2 - 1;
		while (idx >= 0 && num[idx] == 0) idx--;
		string str = "";
		if (idx < 0){
			str += "0";
			return str;
		}
		for (int i = idx; i >= 0; i--)
			str += char(num[i] + '0');
		return str;
	}
};


int main(){
	string s1, s2;
	cin >> s1 >> s2;
	Solution sc;
	cout << sc.multiply(s1, s2) << endl;
	return 0;
}