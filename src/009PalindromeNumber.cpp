#include <iostream>
using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
		if (x < 0) return false;
		int tmp = 1;
		while (tmp <= x && tmp < 0x7fffffff / 10) tmp *= 10;
		if (tmp > x) tmp /= 10;
		
		int x1, ln, fn;
		x1 = x;
		while (x > 0){
			ln = x % 10;
			x /= 10;
			
			fn = x1 / tmp;
			x1 = x1 % tmp;
			tmp /= 10;
			
			if (fn != ln) return false; 
		}
		return true;
	}
};


int main(){
	int x;
	cin >> x;
	Solution sc;
	if (sc.isPalindrome(x)) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}