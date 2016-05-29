#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n; 
	string str = "";
	cin >> n;
	for (int i =0; i < 32; i++)
		str += char('0' + (((n >> i) & 1) > 0));
	cout << str << endl;
	reverse(str.begin(), str.end());
	cout << str << endl;
	return 0;
}