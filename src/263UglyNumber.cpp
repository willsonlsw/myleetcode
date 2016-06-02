#include <iostream>
using namespace std;

class Solution{
public:
	bool isUgly(int num){
		while (num % 2 == 0) num /= 2;
		while (num % 3 == 0) num /= 3;
		while (num % 5 == 0) num /= 5;
		if (num == 1) return true;
		else return false;
	}
};

int main(){
	int x;
	Solution sc;
	while (cin >> x) {
		cout << sc.isUgly(x) << endl; 
	}
	return 0;
}